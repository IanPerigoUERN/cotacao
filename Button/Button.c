#include "Button.h"

#define LED_BLUE 12  // Pino do LED azul

// Inicializa o botão e o LED
void init_button_and_led() {
    // Configuração do LED como saída
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, false);  // Inicialmente, o LED está apagado

    // Configuração do Botão A como entrada com pull-up
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
}

// Atualiza o estado do LED com base no estado do botão
void update_led_state() {
    bool button_a_state = gpio_get(BUTTON_A);  // Lê o estado do botão
    gpio_put(LED_BLUE, button_a_state);  // Acende o LED se o botão estiver solto, apaga se pressionado
}