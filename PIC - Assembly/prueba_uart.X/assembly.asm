#include <xc.inc>

psect   barfunc,local,class=CODE,delta=2 ; PIC10/12/16
// psect   barfunc,local,class=CODE,reloc=2 ; PIC18

global _bar //; extern of bar function goes in the C source file
_bar:
    movf PORTA,W   // ; here we use a symbol defined via xc.inc
    return
