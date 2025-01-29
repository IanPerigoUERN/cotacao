#ifndef JOYSTICH_H
#define JOYSTICH_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define JOYSTICK_X_PIN 26
#define JOYSTICK_Y_PIN 27

// Inicializa o joystick (configura os pinos ADC)
void init_joystick();

// Lê o valor do eixo X do joystick
uint16_t read_joystick_x();

// Lê o valor do eixo Y do joystick
uint16_t read_joystick_y();

#endif