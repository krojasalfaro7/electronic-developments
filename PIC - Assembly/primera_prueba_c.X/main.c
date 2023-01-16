/*
 * File:   main.c
 * Author: Kevin Rojas
 *
 * Created on 24 de marzo de 2019, 04:02 PM
 */


#include <xc.h>
#include <pic16f877a.h>
//#include <strings.h>
#include <string.h>
//#include <usart.h>

#define True 1
#define False 0

void main(void) {
    TRISB = 0xff; TRISC = 0x00;
    TRISD =  0x00;
    PORTD = PORTC = 0x00;
    
    while(True){
        PORTD = PORTB;
        bar();
        //asm("bsf PORTC,0");
        for (int i = 0; i < 100; i++){
            asm("nop");
        }
        bar2();
        //asm("bcf PORTC,0");
        for (int i = 0; i < 100; i++){
            asm("nop");
        }
    }
    return;
}
