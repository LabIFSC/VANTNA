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

static UIContext UI((LCDSettings){ PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7 }, PIN_KINPUT);

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

  if(counter >= 2)
  {
    counter = 0;
    UI.display_->clear();

    // Serial.print("aB: "); Serial.print(B.getAngulo());
    // Serial.print("aD: "); Serial.print(anguloDest_);

    // Bussola: 00.00

    if(dist_ > 0)
    {
      UI.display_->setCursor(0,0);
      UI.display_->println("Dist: ");
      UI.display_->setCursor(0, 1);
      UI.display_->print(dist_);
    }
    else
    {
      UI.display_->print("Procurando");
      UI.display_->setCursor(0, 1);
      UI.display_->println("Satelites...");
    }
  }

  counter++;  


  // Serial.print("Distancia:");
  // Serial.print(wp2.distancia(wp1),16);
  
  // Serial.print(" Angulo:");
  // Serial.println(wp2.calcularAngulo(wp1),16);
  // delay(10000);

}


/*
void loop() 
{
  
  GPS_A.loop();

  // --Só roda se a porta H tiver ligada
  M_bb.gira_horario(127);
  M_be.gira_horario(127);

  UI.Update();
  UI.Draw();
  // TODO: Piloto automático
  // Ver: https://stackoverflow.com/questions/67017134/find-rotation-matrix-to-align-two-vectors
  // Ver: https://stackoverflow.com/questions/55169099/animating-a-3d-vector
  // 1 - Definir ponto inicial (ix, iy) Ponto final (dx, dy)
  // 2 - Calcular hipotenusa do triangulo retângulo formado pelos pontos ((dx-ix), (dy-iy)) | Também é distância a ser percorrida
  // 3 - Calcular o ângulo a partir da posição atual e o destino
  //   - Realizar operação nos motores para reduzir o ângulo até 0

  // Exibir lista de opcoes do menu principal
  // TODO: Controle de rotinas: Definir quanto tempo deve ser alocado para cada tarefa
  // A cada x frames/loops, atualizar UI
  // A cada x frames/loops, chamar update do sistema
  // A cada x frames/loops, enviar os novos comandos para os motores
}
*/