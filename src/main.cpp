//////
#include <Arduino.h>
#include <Motor.h>
#include "LiquidCrystal.h"
#include "Bussola.h"
#include "LED.h"
#include "GPS.h"

#define HBRIDGE_5V A1


// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
Motor M1(PIN7, PIN6, PIN3); /** In1 | In2 | EnableA */
Motor M2(PIN5, PIN4, PIN2); /** In3 | In4 | EnableB */
Bussola B;

GPS GPS_A;

// LiquidCrystal lcd_test;

#define LCD_WIDTH 16
#define LCD_HEIGHT 2

void InitLCD()
{
  // lcd_test.begin(LCD_WIDTH, LCD_HEIGHT);
  // lcd_test.clear();
  // lcd_test.setCursor(0, 0);
}

void setup() 
{
  M1.setup();
  M2.setup();
  B.setUp();

  GPS_A.setUp();


  // TODO: Inicializar periféricos
  // - Bússola
  // - GPS
  // - Display LCD (IO)
  // - Teclado (IO)

  // TODO: Inicilizar GUI do painel de LCD
  //Serial.begin(9600);
  //Serial.print("Hello, world");
}

// vcc gnd  scl  sda  


void loop() 
{
  float a = B.getAngulo();
  lcd.setCursor(1,0);
  lcd.print(a);
  delay(1000);

  GPS_A.loop();

  // TODO: Ouvir por chamadas através dos botões para funções especificadas
  // callbacks[buttons] = { [MENU_A] = enviar_coordenadas(...) }
}
//////