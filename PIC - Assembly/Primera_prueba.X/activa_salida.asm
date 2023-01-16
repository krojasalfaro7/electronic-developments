#include <pic16f877a.inc>

//__CONFIG _XT_OSC & _PWRTE_ON & _BODEN_ON & _CP_OFF & _WDT_OFF & _LVP_OFF
    
//CBLOCK 0x20
//mini_buffer
//ENDC


org 0;
bsf STATUS,5 // BANK 1
    clrf PORTD
    movlw 0xff		
    movwf PORTB 
bcf STATUS,5; // BANK 0
    
clrf PORTD // Refrescando el puerto de salida
clrf PORTB // Refrescando el puerto de entrada
    
REPITE movf PORTB,W
movwf PORTD
goto REPITE
