/*
 * File:   principal.c
 * Author: Kevin Rojas
 *
 * Created on April 1, 2019, 5:07 PM
 */


#include <xc.h>
#include <pic18f27j53.h>
#define _XTAL_FREQ 8000000

#define True 1
#define False 0

void USART_Init(long);
void USART_TxChar(char);
//char USART_RxChar();

#define F_CPU 8000000/64

#define Baud_value (((float)(F_CPU)/(float)baud_rate)-1)

/************************CODE FOR ECHO GENERATION USING USART*****************/
void main()
{
    OSCCON=0x72;    
    char data_in;
    USART_Init(9600);         /*initialize USART operation with 9600 baud rate*/ 
    __delay_ms(100);
    data_in = 'a';
    while(True)
    {
        //data_in=USART_RxChar();
        USART_TxChar(data_in);
    }
    
}

/*****************************USART Initialization*******************************/
void USART_Init(long baud_rate)
{
    float temp;
    TRISC6=0;                       /*Make Tx pin as output*/
    TRISC7=1;                       /*Make Rx pin as input*/
    temp=Baud_value;     
    SPBRG=(int)temp;                /*baud rate=9600, SPBRG = (F_CPU /(64*9600))-1*/
    TXSTA=0x20;                     /*Transmit Enable(TX) enable*/ 
    RCSTA=0x90;                     /*Receive Enable(RX) enable and serial port enable */
}
/******************TRANSMIT FUNCTION*****************************************/ 
void USART_TxChar(char out)
{        
        while(TXIF==0);            /*wait for transmit interrupt flag*/
        TXREG=out;                 /*transmit data via TXREG register*/    
}
/*******************RECEIVE FUNCTION*****************************************/

/*char USART_RxChar()
{

while(RCIF==0);       //wait for receive interrupt flag
    if(RCSTAbits.OERR)
    {           
        CREN = 0;
        NOP();
        CREN=1;
    }
    return(RCREG);   //receive data is stored in RCREG register and return
            
}*/
