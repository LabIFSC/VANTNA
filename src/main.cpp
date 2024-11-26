#include <Arduino.h>
#include <Motor.h>

#define HBRIDGE_5V A1

void test_motor_w_potentiometer();

// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
Motor M1(PIN7, PIN6, PIN3); /** In1 | In2 | EnableA */
Motor M2(PIN5, PIN4, PIN2); /** In3 | In4 | EnableB */

void setup() 
{
  M1.setup();
  M2.setup();

  digitalWrite(HBRIDGE_5V, HIGH); // Tentativa de mandar 5v para ponte H pelo Arduino
  // digitalWrite(HBRIDGE_12V, HIGH); // ???

  // Init pins for potentiometer test
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() 
{
  test_motor_w_potentiometer();

  delay(1000);
}

void test_motor_w_potentiometer()
{

  long speed_m1 = map(analogRead(A0), 0, 1023, -255, 255);
  long speed_m2 = map(analogRead(A1), 0, 1023, -255, 255);

  if((speed_m1>=-10)&&(speed_m1<=10))
    M1.freia();
    else{
  if(speed_m1<0)
      M1.gira_antihorario(-speed_m1);
  else
      M1.gira_horario(speed_m1);
    }

    if((speed_m2>=-10)&&(speed_m2<=10))
    M2.freia();
    else{
  if(speed_m2<0)
      M2.gira_antihorario(-speed_m2);
  else
      M2.gira_horario(speed_m2);
    }
  // M2.gira_antihorario(speed_m2);
}