/////////////////////////////////////////////////////////////////////////////
//Archivo de cabecera para el uso del m�dulo USART PIC ejemplos con el XC8///
/////////////////////////////////////////////////////////////////////////////
 
#ifndef USART_H
#define	USART_H
 
void iniciar_usart();//funci�n para iniciar el USART PIC as�ncron, 8 bits, 9600 baudios
unsigned char recibe_caracter_usart();//funci�n para la recepci�n de caracteres
void envia_caracter_usart(unsigned char);//funci�n para la transmisi�n de caracteres
void envia_cadena_usart(char*);//funci�n para la transmisi�n de cadenas de caracteres
 
///////////////////////////////////////////////
//inicializaci�n del m�dulo USART PIC modo as�ncrono
//en una funci�n, a 8bits,a 9600 baudios
/////////////////////////////////////////////////////
void iniciar_usart(){
     TRISCbits.TRISC7=1;//pin RX como una entrada digital
     TRISCbits.TRISC6=0;//pin TX como una salida digital
     TXSTA=0b00100110;// 8bits, transmisi�n habilitada, as�ncrono, alta velocidad
     RCSTA=0b10010000;//habilitado el USART PIC, recepci�n 8 bits,  habilitada, as�ncrono
     SPBRG=25;//para una velocidad de 9600baudios con un oscilador de 4Mhz
    }
 
///////////////////////////////////////////////
//recepci�n de datos del m�dulo USART PIC modo as�ncrono
////////////////////////////////////////////////////////////
unsigned char recibe_caracter_usart(){
    if(PIR1bits.RCIF==1){//si el bit5 del registro PIR1 se ha puesto a 1
    return RCREG;//devuelve el dato almacenado en el registro RCREG
    }
    else//sino
        return;//retorna sin hacer nada
}
 
///////////////////////////////////////////////
//transmisi�n de datos del m�dulo USART PIC modo as�ncrono
///////////////////////////////////////////////
void envia_caracter_usart(unsigned char caracter){
        while(TXSTAbits.TRMT==0);// mientras el registro TSR est� lleno espera
	TXREG = caracter;//cuando el el registro TSR est� vacio se envia el caracter
}
 
 
///////////////////////////////////////////////
//transmisi�n de cadenas de caracteres con el m�dulo USART PIC modo as�ncrono
///////////////////////////////////////////////
void envia_cadena_usart(char* cadena){//cadena de caracteres de tipo char
    while(*cadena !=0x00){//mientras el �ltimo valor de la cadena sea diferente
                          //de el caracter nulo
        envia_caracter_usart(*cadena);//transmite los caracteres de cadena
        cadena++;//incrementa la ubicaci�n de los caracteres en cadena
                 //para enviar el siguiente caracter de cadena
    }
}
 
#endif	/* USART_H */