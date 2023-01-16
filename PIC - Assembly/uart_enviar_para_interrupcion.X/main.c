/*
 * File:   main.c
 * Author: Kevin Rojas
 *
 * Created on 28 de marzo de 2019, 11:09 AM
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
    
    TRISD = TRISC = 0x00;           // Puerto D como salida
    TRISB = 0xFF;          // Puerto B como entrada
    PORTC = 0x00;  //Refrescando los puertos de salida
    PORTD = 0x00;          // Resfrescando el puerto D
    
    iniciar_usart();
    configurar_interrupcion();
    
    while (True){
        PORTD = PORTB;
        __delay_ms(500);
    }
}/* void main(void) */