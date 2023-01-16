    processor 16f877a
    include <p16f877a.inc>
    
    CBLOCK 0x21
    buffer
    ENDC
    
    org 0x00 
    
    bsf STATUS,RP0
    clrf PORTD
    movlw 0xff
    movwf PORTB
    bcf STATUS,RP0
    
    clrf PORTD
    
    REPITE movf PORTB,W
    movwf PORTD
    goto REPITE
    
    END