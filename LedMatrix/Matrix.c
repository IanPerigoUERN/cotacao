#include "Matrix.h"

void ws2818_init(PIO pio, int sm, uint pin) {
    uint offset = pio_add_program(pio, &ws2818_program);
    ws2818_program_init(pio, sm, offset, pin, 800000, false);
}

// Função para enviar cor para o NeoPixel
void set_pixel_color(uint32_t color) {
    for (int i = 0; i < NUM_LEDS; i++) {
        pio_sm_put_blocking(pio0, 0, color << 8);  // Envia a cor para todos os LEDs
    }
}



uint32_t rgb_to_grb(uint8_t r, uint8_t g, uint8_t b) {
    return ((g << 16) | (r << 8) | b);  // Formato GRB usado pelo WS2812
}
