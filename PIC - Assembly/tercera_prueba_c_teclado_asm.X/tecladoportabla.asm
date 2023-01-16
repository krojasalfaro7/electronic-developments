#include <xc.inc>

;PROCESSOR PIC16F877A
;include <p16f877a.inc>


/*; When assembly code is placed in a psect, it can be manipulated as a
; whole by the linker and placed in memory.  
;
; In this example, barfunc is the program section (psect) name, 'local' means
; that the section will not be combined with other sections even if they have
; the same name.  class=CODE means the barfunc must go in the CODE container.
; PIC18's should have a delta (addressible unit size) of 1 (default) since they
; are byte addressible.  PIC10/12/16's have a delta of 2 since they are word
; addressible.  PIC18's should have a reloc (alignment) flag of 2 for any
; psect which contains executable code.  PIC10/12/16's can use the default
; reloc value of 1.  Use one of the psects below for the device you use:
*/
psect   barfunc,local,class=CODE,delta=2 ; PIC10/12/16

global _barr ; extern of bar function goes in the C source file
_barr:
    bsf PORTC,1    ; here we use a symbol defined via xc.inc
    return
global _barr2 ; extern of bar function goes in the C source file
_barr2:
    bcf PORTC,1    ; here we use a symbol defined via xc.inc
    return
    
