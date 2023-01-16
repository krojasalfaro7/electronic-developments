/*
 * File:   principal.c
 * Author: Kevin Rojas
 *
 * Created on 1 de abril de 2019, 02:34 PM
 */


#include <xc.h>
#include <pic18f27j53.h>
#define _XTAL_FREQ 8000000

#define True 1
#define False 0

TXSTA1bits.TX9 = 0;



void main(void) {
    
    TXREG1 = 'A';
    //PORTC = 0x00;
    while (True){
     
    //__delay_ms(100);
    TXREG1 = 'A';    
    
    //TXREG1=RCREG1; 
    //__delay_ms(100);
 
    }
    return;
}
