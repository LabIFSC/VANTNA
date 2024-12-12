//////
#include <Arduino.h>
#include <Motor.h>
#include "Bussola.h"
#include "LED.h"
#include "GPS.h"
#include "UIContext.h"

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
}

void loop() 
{
  GPS_A.loop();

  /** Só roda se a porta H tiver ligada */
  M_be.gira_horario(127);
  M_bb.gira_horario(127);

  // UI.Update();
  // UI.Draw();
  // TODO: Piloto automático
  // 1 - Definir ponto inicial (ix, iy) Ponto final (dx, dy)
  // 2 - Calcular hipotenusa do triangulo retângulo formado pelos pontos ((dx-ix), (dy-iy))
  // 3 - Calcular o ângulo a partir da posição atual e o destino
  //   - Realizar operação nos motores para reduzir o ângulo até 0

  // Exibir lista de opcoes do menu principal
  // TODO: Controle de rotinas: Definir quanto tempo deve ser alocado para cada tarefa
  // A cada x frames/loops, atualizar UI
  // A cada x frames/loops, chamar update do sistema
  // A cada x frames/loops, enviar os novos comandos para os motores
}