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

    // Configuração do Botão B como entrada com pull-up
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
}

// Atualiza o estado do LED com base no estado dos botões
void update_led_state() {
    bool button_a_state = gpio_get(BUTTON_A);  // Lê o estado do Botão A
    bool button_b_state = gpio_get(BUTTON_B);  // Lê o estado do Botão B

    if (button_a_state == 0) {  // Se o Botão A for pressionado (LOW)
        gpio_put(LED_BLUE, true);  // Acende o LED
    } else if (button_b_state == 0) {  // Se o Botão B for pressionado (LOW)
        gpio_put(LED_BLUE, false);  // Apaga o LED
    }
}
