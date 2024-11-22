#include <Arduino.h>
#include <Motor.h>

// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
Motor M1(7,6,3);
Motor M2(5,4,2);

void setup() 
{
  // put your setup code here, to run once:
  M1.setup();
  M2.setup();
  pinMode(A0,INPUT);
}

void loop() 
{
  M2.gira_horario(255);
  delay(1000);
}
