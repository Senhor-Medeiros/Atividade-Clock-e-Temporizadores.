# Projeto 6-A: **Sistema de Semáforo com Raspberry Pi Pico**
**EMBARCATECH - UNIDADE 04**

## Desenvolvedora
**Desenvolvido pela aluna Graziele Coelho de Alencar**

## Links:
- Execução na BitDogLab:
https://drive.google.com/file/d/1MiMP5I55yF8cWqjxPUIdXtgwczMS_B2A/view?usp=drive_link

- Execução no Wokwi integrado no VS Code:
https://drive.google.com/file/d/1nOIxOAVnCOcZ1oKCbkF6jDMOHvSei1iU/view?usp=drive_link

## **Descrição do Projeto**
Este projeto implementa um sistema de semáforo simples utilizando o microcontrolador Raspberry Pi Pico, LEDs e a biblioteca Pico SDK. O programa controla os estados dos LEDs (vermelho, amarelo e verde) em intervalos regulares, simulando o funcionamento de um semáforo. Além disso, o estado atual do semáforo é exibido pela porta serial.

## **Funcionalidades**
1. Estados do semáforo:

- Vermelho: Inicialmente ligado por 3 segundos.

- Amarelo: Acende após o vermelho por 3 segundos.

- Verde: Acende após o amarelo por 3 segundos.

- O ciclo reinicia após o estado verde.

2. Mensagens na porta serial:

- Exibe o estado atual do semáforo a cada 1 segundo no formato:

*Semáforo funcionando. Estado atual: [COR]*

## **Hardware Utilizado**

1. Raspberry Pi Pico

2. 3 LEDs:

- LED vermelho conectado ao GPIO 13

- LED amarelo conectado ao GPIO 12 (representado como azul no BitDogLab)

- LED verde conectado ao GPIO 11

3. 3 resistores de 330Ω (um para cada LED)

4. Conexões ao GND: Todos os LEDs conectados ao pino GND do Raspberry Pi Pico.

## **Esquema de Ligações**

**Configuração dos LEDs:**

- GPIO 13 → Resistor → LED Vermelho → GND

- GPIO 12 → Resistor → LED Amarelo → GND

- GPIO 11 → Resistor → LED Verde → GND

## **Pré-requisitos**

**1. Ferramentas Necessárias:**

- Ambiente de desenvolvimento VS Code configurado com o Pico SDK.

- Ferramenta para monitorar a porta serial (ex: Terminal Serial no VS Code).

**2. Configuração do VS Code:**

- Certifique-se de que o Pico SDK está corretamente configurado.

- O CMake e o compilador ARM GCC devem estar instalados.

## **Instruções para Compilação e Execução**

1. Clone ou copie este repositório para o seu ambiente de desenvolvimento;

2. Navegue até a pasta do projeto;

3. Configure o build com o CMake;

4. Compile o programa;

5. Carregue o binário gerado no Raspberry Pi Pico;

6. Abra um terminal serial para monitorar as mensagens enviadas pelo programa.

## **Resultados Esperados**

**1. Quando o sistema é iniciado:**
- O LED vermelho acende por 3 segundos
- A mensagem inicial aparece na porta serial (terminal do VS Code):
*Sistema de semáforo iniciado.*

**2. Durante a execução:**
- O estado dos LEDs alterna entre vermelho → amarelo → verde a cada 3 segundos.
- A mensagem correspondente ao estado atual do semáforo é exibida pela porta serial a cada 1 segundo, como:
Semáforo funcionando. Estado atual: Vermelho
Semáforo funcionando. Estado atual: Vermelho
Semáforo funcionando. Estado atual: Vermelho
Semáforo funcionando. Estado atual: Amarelo
Semáforo funcionando. Estado atual: Amarelo

## **Simulação no BitDogLab**
**O projeto pode ser testado no BitDogLab, onde:**
- LED vermelho: GPIO 13.

- LED amarelo (azul no BitDogLab): GPIO 12.

- LED verde: GPIO 11.

**Observações:**
*Certifique-se de que os LEDs estão corretamente configurados com resistores de 330Ω.*
*Na execução na BitDogLab, acende o LED azul, pois se fosse acionar o LED que é na cor amarela seria necessário combinar demais LEDs e a simulação no Woki no VS Code não sairia igual ao exemplo do professor Ricardo.*



