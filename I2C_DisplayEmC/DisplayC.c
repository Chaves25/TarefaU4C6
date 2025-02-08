#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"

#define I2C_PORT i2c1           // Define o barramento I2C (i2c1)
#define I2C_SDA 14              // Pino SDA para comunicação I2C
#define I2C_SCL 15              // Pino SCL para comunicação I2C
#define ENDERECO_OLED 0x3C      // Endereço I2C do display SSD1306
#define I2C_BAUD 400000         // Baud rate para I2C a 400kHz
#define WIDTH 128               // Largura do display OLED
#define HEIGHT 64               // Altura do display OLED

// Função para inicializar a comunicação I2C
void i2c_init_custom() {
    i2c_init(I2C_PORT, I2C_BAUD); // Inicializa o I2C com baud rate definido
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Configura pino SDA
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Configura pino SCL
    gpio_pull_up(I2C_SDA); // Habilita pull-up para SDA
    gpio_pull_up(I2C_SCL); // Habilita pull-up para SCL
}

// Função para configurar e inicializar o display OLED
void init_oled(ssd1306_t *ssd) {
    ssd1306_init(ssd, WIDTH, HEIGHT, false, ENDERECO_OLED, I2C_PORT); // Inicializa o display OLED
    ssd1306_config(ssd); // Configura o display OLED
    ssd1306_send_data(ssd); // Envia dados para o display
}

// Função para desenhar o símbolo simplificado do Vasco (exemplo abstrato)
void draw_vasco_symbol(ssd1306_t *ssd) {
    // Desenha um retângulo central para representar o escudo simplificado
    ssd1306_rect(ssd, 10, 10, 108, 44, true, false);

    // Desenha o texto "VASCO" no centro
    ssd1306_draw_string(ssd, "VASCOOOOO", 30, 20);

    // Atualiza o display
    ssd1306_send_data(ssd);
}

// Função principal do programa
int main() {
    stdio_init_all(); // Inicializa as bibliotecas padrão

    // Inicializa a comunicação I2C e o display OLED
    i2c_init_custom();
    ssd1306_t ssd;
    init_oled(&ssd);

    // Limpa o display, preenchendo com preto
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

    // Desenha o símbolo simplificado do Vasco
    draw_vasco_symbol(&ssd);

    // Atraso de 5 segundos antes de reiniciar
    sleep_ms(5000);

    return 0;
}
