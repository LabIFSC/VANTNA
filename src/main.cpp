#include <Arduino.h>
#include <Motor.h>

// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
/** In1 | In2 | EnableA */
Motor M1(7,6,3);
/** In3 | In4 | EnableB */
Motor M2(5,4,2);

void test_motor_w_potentiometer();

void setup() 
{
  // put your setup code here, to run once:
  M1.setup();
  M2.setup();
  pinMode(A0,INPUT);

  pinMode(A7, INPUT);
  pinMode(A6, INPUT);
  pinMode(A1, INPUT);
}

void loop() 
{
  // test_motor_w_potentiometer();

  test_motor_w_potentiometer();

  digitalWrite(A1, HIGH); // Ligar a ponte H

  // test

  long speed_m1 = 255;
  long speed_m2 = -255;

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