#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//Módulos adicionados
#include "APIconection/CREDENTIALS.h"
#include "APIconection/http_server.h"
#include <Display/Display.h>
#include "LedMatrix/ws2818b.pio.h"
#include "LedMatrix/Matrix.h"
#include "Button/Button.h"


int main() {
    PIO pio = pio0;
    int sm = 0;  // State machine 0
    ws2818_init(pio, sm, LED_PIN);
    
    while(true){
    set_pixel_color(rgb_to_grb(255, 0, 0));
    sleep_ms(700);
    set_pixel_color(rgb_to_grb(0, 255, 0));
    sleep_ms(700);
    set_pixel_color(rgb_to_grb(0, 0, 255));
    sleep_ms(700);
    }
}