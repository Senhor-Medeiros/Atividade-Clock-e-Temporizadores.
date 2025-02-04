#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos GPIO
#define GREEN_LED_PIN 11   // LED verde
#define YELLOW_LED_PIN 12 // LED amarelo (que na BitDogLab é azul)
#define RED_LED_PIN 13  // LED vermelho

// Variável global para armazenar a cor atual
const char *current_color = "Vermelho";

// Função de callback para o temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    static int state = 0;

    // Controle dos LEDs baseado no estado atual
    switch (state) {
        case 0: // Amarelo aceso
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 1);
            gpio_put(GREEN_LED_PIN, 0);
            current_color = "Amarelo";
            state = 1;
            break;
        case 1: // Verde aceso
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 1);
            current_color = "Verde";
            state = 2;
            break;
        case 2: // Vermelho aceso
            gpio_put(RED_LED_PIN, 1);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 0);
            current_color = "Vermelho";
            state = 0;
            break;
    }

    return true; // Retorna true para manter o temporizador ativo
}

int main() {
    // Inicializa o SDK
    stdio_init_all();

    // Configura os pinos GPIO como saída
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    // Configura o estado inicial (LED vermelho aceso)
    gpio_put(RED_LED_PIN, 1);
    gpio_put(YELLOW_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    current_color = "Vermelho";

    // Mensagem inicial na porta serial
    printf("Sistema de semáforo iniciado.\n");

    // Cria o temporizador periódico
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (1) {
        // Exibe a mensagem na porta serial de acordo com o estado atual
        printf("Semáforo funcionando... Estado atual: %s\n", current_color);
        sleep_ms(1000); // Aguarda 1 segundo antes de exibir novamente
    }

    return 0;
}
