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
}

void loop() 
{
  test_motor_w_potentiometer();
}