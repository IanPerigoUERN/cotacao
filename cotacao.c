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
#include "Button/Button.h"


int main() {
    stdio_init_all();  // Inicializa a saída padrão
    
    // Testes dos módulos
    init_button_and_led();  // Inicializa o botão e o LED

    while (true) {
        update_led_state();  // Atualiza o estado do LED com base no botão
        sleep_ms(50);  // Pequeno delay para evitar leituras inconsistentes
    }
    ConfigDisplay();
    DisplayMessage();
    
    
    // Fim dos testes

    sleep_ms(10000);
    printf("Iniciando servidor HTTP\n");

    // Inicializa o Wi-Fi
    if (cyw43_arch_init()) {
        printf("Erro ao inicializar o Wi-Fi\n");
        return 1;
    }

    cyw43_arch_enable_sta_mode();
    printf("Conectando ao Wi-Fi...\n");

    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
        printf("Falha ao conectar ao Wi-Fi\n");
        return 1;
    }else {
        printf("Connected.\n");
        // Read the ip address in a human readable way
        uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);
        printf("Endereço IP %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    }

    printf("Wi-Fi conectado!\n");
    printf("Para ligar ou desligar o LED acesse o Endereço IP seguido de /led/on ou /led/off\n");

    // Configura o LED como saída
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Inicia o servidor HTTP
    start_http_server();
    
    // Loop principal
    while (true) {
        cyw43_arch_poll();  // Necessário para manter o Wi-Fi ativo
        sleep_ms(100);
    }

    cyw43_arch_deinit();  // Desliga o Wi-Fi (não será chamado, pois o loop é infinito)
    return 0;
}