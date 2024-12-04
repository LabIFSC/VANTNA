#include <Arduino.h>
#include "LED.h"

/** TODO: Make a class based into this lib */

int contador = 0;
unsigned long delayBotao;
int estadoBotaoAnt = btNENHUM;

LiquidCrystal lcd(pinRs, pinEn, pinD4, pinD5, pinD6, pinD7);
//Para o exemplo de uso
String descBotao[6] = {"", "Select", "Esquerda", "Abaixo", "Acima", "Direita"};

void estadoBotao(int botao) {
  //Quando um botao estiver apertado
  if (botao != btNENHUM) {
     Serial.println(botao);
  }

  //Quando o botao for apertado ou solto
  if ((millis() - delayBotao) > tempoDebounce) {
     if ((botao != btNENHUM) && (estadoBotaoAnt == btNENHUM) ) {
        botaoApertado(botao); 
        delayBotao = millis();
     }

     if ((botao == btNENHUM) && (estadoBotaoAnt != btNENHUM) ) {
        botaoSolto(estadoBotaoAnt); 
        delayBotao = millis();
     }
  }

  estadoBotaoAnt = botao;
}

void botaoApertado(int botao) {
  //Quando um botão for apertado

  //Para o exemplo de uso
  contador++;
  lcd.clear();
  lcd.print(descBotao[botao]);
  lcd.setCursor(14,0);
  lcd.print(contador);
  lcd.setCursor(0,1);
  lcd.print("apertado");
}

void botaoSolto(int botao) {
  //Quando um botão for solto


  //Para o exemplo de uso
  lcd.clear();
  lcd.print(descBotao[botao]);
  lcd.setCursor(14,0);
  lcd.print(contador);
  lcd.setCursor(0,1);
  lcd.print("solto");
}

