#include <Arduino.h>
#include <Motor.h>

// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
Motor M1(7,6,3);
Motor M2(5,4,2);

void test_motor_w_potentiometer();

void setup() 
{
  // put your setup code here, to run once:
  M1.setup();
  M2.setup();
  pinMode(A0,INPUT);
}

void loop() 
{
  delay(1000);
}

void test_motor_w_potentiometer()
{
  char offset = 127;

  long speed_m1 = map(analogRead(A0), 0, 1023, 0, 255);
  long speed_m2 = map(analogRead(A1), 0, 1023, 0, 255);
  
  M1.gira_horario(speed_m1 + offset /* 0 ~ 128 => 128 -> 255 */);
  M1.gira_antihorario(speed_m1 + offset /* -128 ~ 0 */);
}