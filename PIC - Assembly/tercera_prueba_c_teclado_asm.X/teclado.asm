#include <xc.inc>
//#include <pic16f877a.inc>

psect   tecladofunc,local,class=CODE,delta=2 

global _teclado 
_teclado:

    clrf TRISD
    bsf PORTB,0
    movlw 0xff
    movwf PORTD
    return
    
/*global _Umul8,_mult1,_mult2,_res16hi,_res16lo
psect   umul8,local,class=CODE,delta=2
_Umul8:
        movf    _mult1,w
        clrf    _res16hi
        clrf    _res16lo
        bcf     CARRY
    irp bit,0,1,2,3,4,5,6,7
        btfsc   _mult2,bit
        addwf   _res16hi,f
        rrf     _res16hi,f
        rrf     _res16lo,f
    endm
        return
    
    */