# Projeto: Controle de LEDs e Display SSD1306 com Interrupções e UART

## Descrição

Este projeto utiliza a placa de desenvolvimento BitDogLab, com o microcontrolador RP2040, para controlar LEDs comuns e LEDs endereçáveis WS2812, além de exibir informações em um display SSD1306 via comunicação I2C. A interação com o sistema é realizada através de botões e entrada de caracteres via UART (Serial Monitor).

### Objetivos:
- Controlar LEDs RGB e LEDs WS2812 utilizando interrupções e debouncing.
- Exibir caracteres no display SSD1306 a partir da entrada via UART.
- Implementar funcionalidades para controle de LEDs com botões físicos (A e B).

## Componentes Utilizados
- **Matriz de LEDs 5x5 WS2812** (conectada à GPIO 7)
- **LED RGB** (conectado às GPIOs 11, 12 e 13)
- **Botão A** (conectado à GPIO 5)
- **Botão B** (conectado à GPIO 6)
- **Display SSD1306** (conectado via I2C, GPIO 14 e GPIO 15)

## Funcionalidades
1. **Entrada de caracteres via PC**:
   - Caracteres digitados no monitor serial são exibidos no display SSD1306.
   - Números de 0 a 9 são mapeados para símbolos na matriz WS2812.
   
2. **Botão A (LED Verde)**:
   - Alterna o estado do LED RGB Verde (ligado/desligado).
   - Mensagens de status são exibidas no display e enviadas ao Serial Monitor.

3. **Botão B (LED Azul)**:
   - Alterna o estado do LED RGB Azul (ligado/desligado).
   - Mensagens de status são exibidas no display e enviadas ao Serial Monitor.

## Requisitos
- **Bibliotecas**:
  - `Wire.h` (para comunicação I2C com o display SSD1306)
  - `Adafruit_SSD1306.h` (para controle do display)
  - `Adafruit_GFX.h` (para gráficos no display)
  
- **Hardware**:
  - A placa de desenvolvimento BitDogLab com RP2040.
  - Conexões físicas conforme especificado nos requisitos do projeto.

## Instruções de Execução

### Passo 1: Conectar os Componentes
- Conecte a Matriz WS2812 à GPIO 7.
- Conecte os pinos do LED RGB às GPIOs 11, 12 e 13.
- Conecte o Botão A à GPIO 5 e o Botão B à GPIO 6.
- Conecte o Display SSD1306 aos pinos I2C: GPIO 14 (SDA) e GPIO 15 (SCL).

### Passo 2: Carregar o Código
1. Abra o **VS Code** e o **PlatformIO**.
2. Clone ou baixe o repositório do projeto.
3. Abra o projeto no VS Code.
4. Selecione o tipo de placa **RP2040**.
5. Compile e faça o upload do código para a placa BitDogLab.

### Passo 3: Teste de Funcionamento
1. Abra o **Serial Monitor** no VS Code.
2. Digite um caractere no monitor serial. Ele será exibido no display SSD1306.
3. Digite um número entre 0 e 9 no monitor serial e observe o símbolo correspondente na matriz WS2812.
4. Pressione o **Botão A** para alternar o LED verde e observe a mudança no display e no Serial Monitor.
5. Pressione o **Botão B** para alternar o LED azul e observe a mudança no display e no Serial Monitor.

## Como Funciona o Código

- **Leitura do Monitor Serial**: O código lê os caracteres digitados no Serial Monitor e os exibe no display SSD1306. Para números de 0 a 9, um símbolo correspondente é exibido na matriz WS2812.
  
- **Interrupções e Debouncing**: As interrupções são utilizadas para detectar os pressionamentos dos botões A e B. O debouncing é implementado via software para garantir que cada pressionamento seja registrado corretamente.

- **Controle dos LEDs**: O código alterna os LEDs RGB verde e azul com base na interação com os botões. O estado dos LEDs é exibido tanto no display quanto no Serial Monitor.

## Estrutura do Código
- **Setup**: Inicializa os componentes (display, LEDs, botões e comunicação serial).
- **Loop**: Lê os caracteres do monitor serial e exibe no display. Também lida com as interrupções dos botões A e B.
- **Interrupções**: Funções que são executadas quando os botões são pressionados, alternando os estados dos LEDs.

## Link do Repositório

- [GitHub - Projeto Controle de LEDs e Display SSD1306](https://github.com/Chaves25/TarefaU4t2.git)



