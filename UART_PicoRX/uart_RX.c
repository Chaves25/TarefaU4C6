#include <stdio.h>
#include "pico/stdlib.h"

#define UART_ID uart0           // Seleciona a UART0
#define BAUD_RATE 115200       // Define a taxa de transmissão
#define UART_TX_PIN 0          // Pino GPIO usado para TX
#define UART_RX_PIN 1          // Pino GPIO usado para RX
#define LED_PIN 11             // Pino GPIO usado para o LED
#define BUFFER_SIZE 100        // Tamanho do buffer para armazenar a mensagem

// Função para inicializar a UART
void uart_init_custom() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART); // Configura pino 0 para TX
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART); // Configura pino 1 para RX
}

// Função para inicializar o LED
void led_init() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

// Função para piscar o LED indicando recebimento de mensagem
void blink_led(int times) {
    for (int i = 0; i < times; i++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(200);
        gpio_put(LED_PIN, 0);
        sleep_ms(200);
    }
}

// Função para processar a mensagem recebida
void process_message(char* message) {
    printf("Mensagem recebida: %s\n", message);
    blink_led(3); // Pisca o LED 3 vezes quando a mensagem é recebida
}

// Função principal do programa
int main() {
    stdio_init_all();         // Inicializa a biblioteca padrão
    uart_init_custom();       // Inicializa a UART
    led_init();               // Inicializa o LED

    char buffer[BUFFER_SIZE]; // Buffer para armazenar a mensagem
    int index = 0;            // Índice do buffer

    while (1) {
        // Verifica se há dados disponíveis para leitura na UART
        if (uart_is_readable(UART_ID)) {
            char c = uart_getc(UART_ID); // Lê o caractere recebido

            // Adiciona o caractere ao buffer
            if (c != '\n') {
                buffer[index++] = c;

                // Verifica se o buffer está cheio
                if (index >= BUFFER_SIZE - 1) {
                    index = 0; // Reinicia o índice se o buffer estiver cheio
                }
            } else {
                // Termina a string e processa a mensagem
                buffer[index] = '\0'; // Adiciona o terminador de string
                process_message(buffer); // Processa a mensagem
                index = 0; // Reinicia o índice para a próxima mensagem
            }
        }

        sleep_ms(10); // Pequeno atraso para evitar sobrecarga no loop principal
    }

    return 0;
}
