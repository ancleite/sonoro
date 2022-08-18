#include <Servo.h>

int pinoLed = 12; //PINO DIGITAL UTILIZADO PELO LED
int pinoSensor = A0; //PINO UTILIZADO PELO SENSOR
int estadoSensor; //VARIÁVEL QUE ARMAZENA O ESTADO DA SAÍDA DO SENSOR
Servo servomotor; //SETA A VARIÁVEL DO SERVOMOTOR
int servoPin = 7; //PINO UTILIZADO PELO SERVOMOTOR

void setup(){
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  servomotor.attach(servoPin); //PREPARA O SERVOMOTOR
  servomotor.write(0); //SETA A POSIÇÃO INICIAL DO SERVOMOTOR
  Serial.begin(1200);
}

void loop(){
  estadoSensor = analogRead(pinoSensor); //LÊ O ESTADO DO SENSOR
  Serial.println(estadoSensor);
 if (estadoSensor < 80){
    digitalWrite(pinoLed, 0); //DESLIGA O LED
    servomotor.write(0); //SETA A POSIÇÃO DO SERVOMOTOR
    
  }
   else if(estadoSensor > 100 and estadoSensor < 120) {
    digitalWrite(pinoLed, 1); //LIGA O LED
    servomotor.write(90); //SETA A POSIÇÃO DO SERVOMOTOR
    delay(1000);
  }
    else if(estadoSensor > 120) {
    digitalWrite(pinoLed, 1); //LIGA O LED
    servomotor.write(180); //SETA A POSIÇÃO DO SERVOMOTOR
    delay(1000);
  }
 
  
}
