#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "pico/stdlib.h"
#include "lwip/tcp.h"
#include "pico/cyw43_arch.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Definindo o pino do LED
#define BLUE_LED_PIN 12

// Definindo a resposta HTTP
/*
#define HTTP_RESPONSE "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n" \
                      "<!DOCTYPE html><html><body>" \
                      "<h1>Controle do LED</h1>" \
                      "<p><a href=\"/led/on\">Ligar LED</a></p>" \
                      "<p><a href=\"/led/off\">Desligar LED</a></p>" \
                      "</body></html>\r\n"
*/
// Declarações das funções

static err_t http_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static err_t connection_callback(void *arg, struct tcp_pcb *newpcb, err_t err);
void start_http_server(void);

#endif // HTTP_SERVER_H
