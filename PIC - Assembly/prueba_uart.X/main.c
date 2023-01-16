/*
 * File:   main.c
 * Author: Kevin Rojas
 *
 * Created on 24 de marzo de 2019, 07:03 PM
 */

//PIC1 DERECHA, se encarga de mandar lo que entra por el puerto B, por USART al PIC DE LA IZQUIERDA

#include <xc.h>
#include <pic16f877a.h>
#include "config.h"
#include "usart.h"

#pragma config FOSC = XT // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 20000000 //frecuencia del oscilador del PIC16F877A

#define True 1
#define False 0

void main(void) {
    iniciar_usart(); // CONFIGURA LOS DETALLES PARA LA COMUNICACIÓN USART, COMO LOS PUERTOS DE ENTRADA Y SALIDA
    config_ports(); // CONFIGURA LOS PUERTOS DE ENTRADA Y SALIDA
    
    while (True){
        envia_caracter_usart(PORTB);
        __delay_us(10);
       PORTD = recibe_caracter_usart();
   }
    
    return;
}