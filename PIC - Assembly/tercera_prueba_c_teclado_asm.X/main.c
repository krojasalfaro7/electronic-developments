/*
 * File:   main.c
 * Author: Kevin Rojas
 *
 * Created on 27 de marzo de 2019, 07:49 PM
 */


#include <xc.h>
//#include "teclado2.s"

#pragma config FOSC = XT // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 20000000  //frecuencia del oscilador del PIC16F877A
//extern void tecladofunc(void);
//extern unsigned int asmvariable;

#define True 1
#define False 0


void main(void) {
    int x;
    TRISC = 0x00;
    PORTC = 0x00;
    TRISB = 0B11110000;
    
 
    //PORTB = 0B00001111;
    //while (True){
    Umul8();
         //asmfuncion();
    __delay_ms(200);
        //x = INDF;
        //PORTC = INDF;
        
    //}
    return;
    
}
