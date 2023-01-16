void setup() {
    pinMode(D5, OUTPUT);
    analogWriteFreq(80000); //80KHz
    //int PWM_duty;    //Ciclo de trabajo al 50%
    //pinMode(2, OUTPUT);
    //analogWrite(D5, PWM_duty = 512);
}
void loop(){
  //Serial.begin(9600);
  int sensorValue = analogRead(A0); //Lectura del ADC 
  int PWM_duty;
  //float voltage = sensorValue * (3.3 / 1023.0); //escalamos a voltaje 
  //Enviamos por el puerto serie
  //Serial.print("ADC= ");
  //Serial.print(sensorValue);
  //Serial.print("  Voltaje= ");
  //Serial.println(voltage); 
  //analogWrite(D5, PWM_duty = analogRead(A0));
  analogWrite(D5, PWM_duty = 512);
  delay(100);
}
