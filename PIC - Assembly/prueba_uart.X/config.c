/*
 * File:   config.c
 * Author: Kevin Rojas
 *
 * Created on 27 de marzo de 2019, 06:55 PM
 */

#include <xc.h>

void config_ports(void) {
    TRISB = 0xff; // Puerto B como ENTRADA
    TRISD = 0x00; // Puerto D como SALIDA
    PORTB = 0x00, PORTD = 0x00; // Refrescabdo puertos
    return;
}
