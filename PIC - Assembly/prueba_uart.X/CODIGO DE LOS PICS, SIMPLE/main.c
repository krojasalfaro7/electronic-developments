/*
 * File:   main.c
 * Author: Kevin Rojas
 *
 * Created on 24 de marzo de 2019, 07:03 PM
 */

//PIC1 DERECHA, se encarga de mandar lo que entra por el puerto B, por USART al PIC DE LA IZQUIERDA

#include <xc.h>
#include "usart.h"
#include <pic16f877a.h>

#define True 1
#define False 0

void main(void) {
    iniciar_usart();
    TRISB = 0xff; // Puerto b como sálida
    PORTB = 0x00;
    
    while (True)
        envia_caracter_usart(PORTB);
    
    return;
}
