/////////////////////////////////////////////////////////////////////////////
//Archivo de cabecera para el uso del módulo USART PIC ejemplos con el XC8///
/////////////////////////////////////////////////////////////////////////////
 
#ifndef USART_H
#define	USART_H
 
void iniciar_usart();//función para iniciar el USART PIC asíncron, 8 bits, 9600 baudios
unsigned char recibe_caracter_usart();//función para la recepción de caracteres
void envia_caracter_usart(unsigned char);//función para la transmisión de caracteres
void envia_cadena_usart(char*);//función para la transmisión de cadenas de caracteres
 
///////////////////////////////////////////////
//inicialización del módulo USART PIC modo asíncrono
//en una función, a 8bits,a 9600 baudios
/////////////////////////////////////////////////////
void iniciar_usart(){
     TRISCbits.TRISC7=1;//pin RX como una entrada digital
     TRISCbits.TRISC6=0;//pin TX como una salida digital
     TXSTA=0b00100110;// 8bits, transmisión habilitada, asíncrono, alta velocidad
     RCSTA=0b10010000;//habilitado el USART PIC, recepción 8 bits,  habilitada, asíncrono
     SPBRG=25;//para una velocidad de 9600baudios con un oscilador de 4Mhz
    }
 
///////////////////////////////////////////////
//recepción de datos del módulo USART PIC modo asíncrono
////////////////////////////////////////////////////////////
unsigned char recibe_caracter_usart(){
    if(PIR1bits.RCIF==1){//si el bit5 del registro PIR1 se ha puesto a 1
    return RCREG;//devuelve el dato almacenado en el registro RCREG
    }
    else//sino
        return;//retorna sin hacer nada
}
 
///////////////////////////////////////////////
//transmisión de datos del módulo USART PIC modo asíncrono
///////////////////////////////////////////////
void envia_caracter_usart(unsigned char caracter){
        while(TXSTAbits.TRMT==0);// mientras el registro TSR esté lleno espera
	TXREG = caracter;//cuando el el registro TSR está vacio se envia el caracter
}
 
 
///////////////////////////////////////////////
//transmisión de cadenas de caracteres con el módulo USART PIC modo asíncrono
///////////////////////////////////////////////
void envia_cadena_usart(char* cadena){//cadena de caracteres de tipo char
    while(*cadena !=0x00){//mientras el último valor de la cadena sea diferente
                          //de el caracter nulo
        envia_caracter_usart(*cadena);//transmite los caracteres de cadena
        cadena++;//incrementa la ubicación de los caracteres en cadena
                 //para enviar el siguiente caracter de cadena
    }
}
 
#endif	/* USART_H */