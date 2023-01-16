;include <pic16f877a.inc>

;__CONFIG _XT_OSC & _PWRTE_ON & _BODEN_ON & _CP_OFF & _WDT_OFF & _LVP_OFF
    
;CBLOCK 0x20
;mini_buffer
;ENDC

STATUS equ 0x03
PORTB equ 0x06
PORTD equ 0x08
 
;org 0
bsf STATUS, 5 ; BANK 1
    clrf PORTD
    movlw 0xff		
    movwf PORTB 
bcf STATUS, 5  ; BANK 0
    
clrf PORTD ; Refrescando el puerto de salida
clrf PORTB ; Refrescando el puerto de entrada
    
repite movf PORTB,W
movwf PORTD
goto repite
    
END