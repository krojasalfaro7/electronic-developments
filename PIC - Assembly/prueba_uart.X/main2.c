/*
 * File:   main2.c
 * Author: Kevin Rojas
 *
 * Created on 24 de marzo de 2019, 08:29 PM
 */
//PIC2(IZQUIERDA)
//Este se encarga de recibir los datos por USART, y mandarlos por el puerto B
/*
#include <xc.h>
#include "usart.h"
#include <pic16f877a.h>

#define True 1
#define False 0

void main(void) {
    
    TRISB = 0x00; // PUERTO B, como salida
    iniciar_usart(); // 
    while (True)
        PORTB = recibe_caracter_usart();
    return;
}
*/