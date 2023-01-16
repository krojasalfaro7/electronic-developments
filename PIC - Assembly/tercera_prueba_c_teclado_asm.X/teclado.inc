;xxxxxxxx BIBLIOTECA DE TECLADO POR TABLA EN INTERRUPCION xxxxxxxxxxxxxxxxxxxxxxxxxxxxx

; Esta biblioteca esta hecha para un teclado matricial 3x4 con resistencias
; de pull down (10K) en todos los pines del teclado, en total 7.

CBLOCK
tecla		; Variable que almacenara el valor de la tecla presionada
valor		; Variable donde estara el valor correspondiente al número del teclado
ENDC		; Este valor puede ser cambiado a corde como se trabaje, 
			; En esta biblioteca se tendra el valor en BCD.

;En la siguiente rutina se intercambiara la condicion de entrada y salida
;del Puerto B, para hallar la tecla pulsada.

TECLADOPORTABLA	
movf PORTB,W	; Inmediatamente se copia el valor de la fila que causo 
andlw 0xf0		; la interrupcion, además se enmascara para solo tomar el nibble mas significativo
movwf tecla		; Se copia en la variable tecla
bsf STATUS,5	; Se accede al banco 1
swapf PORTB,F	; Los nibbles se intercambian para colocar el mas significativo de salida
bcf STATUS,5	; Y el menor de entrada
clrf PORTB		; Se refreca el puerto B para buscar el bit que entro
movf tecla,W	; El valor que entro ahora sale por la misma tecla presionada
movwf PORTB		; Y asi tener el equivalente del numero que se pulso
movf PORTB,W	; Ahora se copia ese valor que estaria dando la posicion donde fue pulsada
andlw 0x0f 		; Se enmascara para no afectar el resultado
addwf tecla,F	; Se suma el valor de la columna con el de la fila teniendo la matrix de la tecla pulsada
bcf INTCON,0	; Como la interrupcion se produce por cambio de flanco, se refresca para no volver a producir la misma interrupcion

; Ya teniendo el valor de la tecla, ahora se decidira a que número corresponde

;Primera Fila

btfss tecla,4	; Si el bit de la primera fila esta en 1 logico	
goto quinta		; Existe la posibilidad de 1,2 ó 3, si no se chequea el siguiente
bcf tecla,4		; Se borra el bit de esta fila para no alterar la tabla
movf tecla,W	; Se tiene listo para comparar con la tabla y asi saber que número es.
call tabla1		; La tabla decidira que valor del teclado es
movwf valor		; Se copia ese número en la variable "valor" 
goto terminar	; Ya listo se procede a salir de la rutina de teclado

; Segunda Fila 

quinta 
btfss tecla,5	; Si es 1 hay posibilidad de 4,5 ó 6
goto sexta		; Si no chequea la siguiente fila
bcf tecla,5
movf tecla,W
call tabla2
movwf valor
goto terminar

sexta 
btfss tecla,6	; Si es 1 hay posibilidad de 7,8 ó 9
goto septima 
bcf tecla,6
movf tecla,W
call tabla3
movwf valor
goto terminar

septima 
btfss tecla,7	; Si es 1 hay posibilidad de *,0 ó #
goto terminar	; Al ser la ultima fila si no es ninguna de las anteriores se sale del programa
bcf tecla,7
movf tecla,W
call tabla4
movwf valor
goto terminar

tabla1 
addwf PCL,F		; Tabla para 1,2 y 3
nop
retlw 1
retlw 2
nop
retlw 3

tabla2 
addwf PCL,F		; Tabla para 4,5 y 6
nop
retlw 4
retlw 5
nop
retlw 6

tabla3 
addwf PCL,F		; Tabla para 7,8 y 9
nop
retlw 7
retlw 8
nop
retlw 9

tabla4 
addwf PCL,F		; Tabla para *,0 y #
nop
retlw '*'
retlw 0
nop
retlw '#'

terminar 
bsf STATUS,5	; Como se intercambio el valor de entrada y salida del Puerto B
swapf PORTB,F	; se deja como estaba antes de la interrupcion
bcf STATUS,5	; para esperar una nueva
bsf PORTB,0
bsf PORTB,1
bsf PORTB,2		; Se enciende nuevamente los bits de las columnas para otra interrupcion
bcf INTCON,0	; Como se hizo un cambio en los registros se refresca la interrupcion para que no se produzca otra vez
return			; Ya listo se sale de la subrutina del teclado


