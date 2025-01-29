#include "joystick.h"

void init_joystick() {
    stdio_init_all(); // Inicializa a comunicação serial
    adc_init(); // Inicializa o ADC

    // Configura os pinos GPIO para leitura do ADC
    adc_gpio_init(JOYSTICK_X_PIN);
    adc_gpio_init(JOYSTICK_Y_PIN);
}

uint16_t read_joystick_x() {
    adc_select_input(0); // Seleciona ADC0 (eixo X)
    return adc_read();   // Retorna o valor lido
}

uint16_t read_joystick_y() {
    adc_select_input(1); // Seleciona ADC1 (eixo Y)
    return adc_read();   // Retorna o valor lido
}
