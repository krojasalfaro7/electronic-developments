#include <xc.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 20000000 //frecuencia del oscilador del PIC16F877A


void configurar_interrupcion(){
    INTCON=0b11000000;//habilita el uso de interrupciones
    PIE1bits.RCIE=1;//habilita la interrupción USART PIC por recepción
    return;
}

