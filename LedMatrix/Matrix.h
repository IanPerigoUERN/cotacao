#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/cyw43_arch.h"
#include "ws2818b.pio.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.


// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7
#define NUM_LEDS 25


extern PIO np_pio;  // Variável para uso da máquina PIO
extern uint sm;     // Variável para o estado da máquina PIO

// Definindo a estrutura de um pixel RGB
typedef struct {
    uint8_t G, R, B;  // Três valores de 8-bits compõem um pixel.
} pixel_t;

typedef pixel_t npLED_t; // Mudança de nome de "struct pixel_t" para "npLED_t" por clareza.

// Declaração do buffer de pixels que formam a matriz
extern npLED_t leds[LED_COUNT];

// Função para configurar e inicializar o PIO para WS2812
void ws2818_init(PIO pio, int sm, uint pin);

// Função para enviar cor para o NeoPixel
void set_pixel_color(uint32_t color);

// Converte RGB para o formato GRB usado pelo WS2812
uint32_t rgb_to_grb(uint8_t r, uint8_t g, uint8_t b);

// Inicializa a máquina PIO para controle da matriz de LEDs
void npInit(uint pin);

// Atribui uma cor RGB a um LED específico
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);

// Limpa o buffer de pixels
void npClear();

// Escreve os dados do buffer nos LEDs
void npWrite();

#endif