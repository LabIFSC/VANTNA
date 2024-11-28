// https://docs.arduino.cc/libraries/liquidcrystal/
#include <LiquidCrystal.h>

//******* CONFIGURACAO DO PROJETO *********
#define pinBotoes A0

#define pinRs 8
#define pinEn 9
#define pinD4 4
#define pinD5 5
#define pinD6 6
#define pinD7 7
#define pinBackLight 10
//*****************************************

#define btNENHUM 0
#define btSELECT 1
#define btLEFT   2
#define btUP     3
#define btDOWN   4
#define btRIGHT  5

#define tempoDebounce 50



void estadoBotao(int botao);
void botaoApertado(int botao);
void botaoSolto(int botao);

extern int estadoBotaoAnt;

extern LiquidCrystal lcd;
extern String descBotao[6];