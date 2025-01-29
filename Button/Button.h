#ifndef BUTTON_H
#define BUTTON_H


#include "pico/stdlib.h"


#define BUTTON_A 5
#define BUTTON_B 6

void init_button_and_led();  // Função para configurar o botão e o LED
void update_led_state();  // Função para atualizar o estado do LED com base no botão

#endif