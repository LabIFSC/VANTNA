//////
#include <Arduino.h>
#include <Motor.h>
#include "Bussola.h"
#include "LED.h"
#include "GPS.h"
#include "UIContext.h"
#include "Coordenada.h"

/**
 * LCD Driver Settings
 * 
 * É preciso também definir LCD_PIN_OVERRITTEN para que esses valores sejam
 * reconhecidos. Do contrário, os valores defaults de LCD.h serão utilizados.
 */
#define PIN_RS 8
#define PIN_EN 9
#define PIN_D4 4
#define PIN_D5 5
#define PIN_D6 6
#define PIN_D7 7
#define PIN_BACKLIGHT 10

/** Shield Keyboard Settings */
#define PIN_KINPUT A0

/** Motors Settings */
#define LMOTOR_IN1 50
#define LMOTOR_IN2 48
#define HBRIDGE_ENA 2

#define RMOTOR_IN1 51   // IN3
#define RMOTOR_IN2 49   // IN4
#define HBRIDGE_ENB 3


/** Init dispositivos e periféricos */
// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
Motor M_bb(LMOTOR_IN1, LMOTOR_IN2, HBRIDGE_ENA);
Motor M_be(RMOTOR_IN1, RMOTOR_IN2, HBRIDGE_ENB);

Bussola B;
GPS GPS_A;

void setup() 
{
  /** Inicializar subsistemas */
  M_bb.setup();
  M_be.setup();

  GPS_A.setUp();
  B.setUp();
  Serial.begin(9600);
}

// wayPoint1: -26.931230, -48.685413

// wayPoint2: -26.931322, -48.685221
/*
Coordenada wp1(-26.927810, -48.646708);
Coordenada wp2(-26.91465439955142, -48.64670090616903);
*/

Coordenada wp1(-26.931230, -48.685413);
Coordenada wp2(-26.931322, -48.685221);

#define MARGEM_DE_ERRO 1 // metro

double dist_;
double anguloDest_;

int counter = 0;

void loop()
{
  Serial.println(B.getAngulo());

  GPS_A.loop();

  if(GPS_A.is_ready)
  {
    Coordenada ponto_atual = GPS_A.get_coordenda();

    dist_ = ponto_atual.distancia(wp1);
    anguloDest_ = ponto_atual.calcularAngulo(wp1);

    // TODO: Pegar diferença de angulo com bussola e girar o carrinho até zerar o angulo
    // TODO: Iterar para  corrigir o angulo
    // TODO: Girar motores até chegar no destino
  }
}