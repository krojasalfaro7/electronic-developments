/*
 * File:   main.c
 * Author: Kevin Rojas
 *
 * Created on 24 de marzo de 2019, 07:03 PM
 */

#include <xc.h>
#include <pic16f877a.h>
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
    TRISB = 0xff;
    TRISCbits.TRISC0 = 1; // Habilita el primer bit del puerto C como entrada
    while (PORTCbits.RC0){
        //if (){ 
            envia_caracter_usart(PORTB);
            __delay_ms(200);
        //}
        //else
        //    __delay_ms(200);
   }
    return;
}