///////////////////////////
/* AUTOR:     BrincandoComIdeias
*  ACOMPANHE: https://www.youtube.com/brincandocomideias ; https://www.instagram.com/canalbrincandocomideias/
*  APRENDA:   https://cursodearduino.net/ ; https://cursoderobotica.net
*  COMPRE:    https://www.arducore.com.br/
*/
#include <Arduino.h>
#include "LED.h"

// extern int contador;
extern int estadoBotaoAnt;
void setup() {
  pinMode(pinBackLight, OUTPUT);
  digitalWrite(pinBackLight, HIGH);

  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  int valBotoes = analogRead(pinBotoes);

  if ((valBotoes < 800) && (valBotoes >= 600)) {
     estadoBotao(btSELECT);
     
  } else if ((valBotoes < 600) && (valBotoes >= 400)) {
     estadoBotao(btLEFT);
     
  } else if ((valBotoes < 400) && (valBotoes >= 200)) {
     estadoBotao(btUP);
     
  } else if ((valBotoes < 200) && (valBotoes >= 60)) {
     estadoBotao(btDOWN);
     
  } else if  (valBotoes < 60) {
     estadoBotao(btRIGHT);
     
  } else {
     estadoBotao(btNENHUM);
  }
}

////////////////////