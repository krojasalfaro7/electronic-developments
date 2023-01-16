/*
 * File:   main.c
 * Author: Kevin Rojas
 *
 * Created on 28 de marzo de 2019, 11:09 AM
 */
#include <xc.h>
#include <pic16f877a.h>
#include "usart.h"
#include "interrupcion.h" // Cabecera para configurar interrupcion por recepcion USART

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
    
    TRISB = PORTB = TRISD = 0x00;    // Puerto B y D como entrada
    
    iniciar_usart();  // Configura bits para transmision y recepcion USART
    configurar_interrupcion(); // Configurar interrupcion USART
    
    PORTD = 0b10101010; // Bits pares apagados, bits impares encendidos
    while (True){       // MIentras sea verdadero (bucle infinito)
        PORTD = (~PORTD); // Complemento de los bits del puerto D (Intercambia entre apagado y encendido)
        __delay_ms(200); // Retardo de 200 milisegundos
    }
}/* void main(void) */

void __interrupt() tcInt(void)
{
    if (PIR1bits.RCIF){
        __delay_ms(50);
        PORTB = recibe_caracter_usart();
    }
    PIR1bits.RCIF = 0;
    return;
}