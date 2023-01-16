#include <strings.h>
#include <string.h>
#define LED_BUTTON 2
#define ON_LED "Enciende_Led"
#define OFF_LED "Apaga_Led"
char str, ptr_str[4];int i,x=5,y=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUTTON, OUTPUT);
  Serial.begin(115200);
  Serial.print("Hello Kevin \n");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    int a = Serial.available();
    for(i=0; i < a; i++){
      //str = Serial.read();
      ptr_str[i] = Serial.read();
      }
  }
  Serial.print("Usted escribio: ");
  Serial.print(ptr_str); Serial.print("\n");

  x= strcmp("A_Led", ptr_str);
  y= strcmp("B_Led", ptr_str);
  
  Serial.print(x);Serial.print(y);
  if(!x){
    Serial.print("Encendiendo...");
    digitalWrite(LED_BUTTON, HIGH); 
    }
  else if(!y){
    Serial.print("Apagando...");
    digitalWrite(LED_BUTTON, LOW);
    }
  else{
    delay(1000);
    } 
  //digitalWrite(LED_BUTTON, HIGH);
  //delay(1000);
  //digitalWrite(LED_BUTTON, LOW);
  //delay(1000);
}
