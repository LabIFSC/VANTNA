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


/** Init dispositivos e periféricos */
// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
Motor M_bb(50, 48, 2); /** In1 | In2 | EnableA */
Motor M_be(51, 49, 3); /** In3 | In4 | EnableB */

Bussola B;
GPS GPS_A;

static UIContext UI((LCDSettings){ PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7 }, PIN_KINPUT);

void setup() 
{
  /** Inicializar subsistemas */
  M_bb.setup();
  M_be.setup();
}

void loop() 
{
  M_be.gira_horario(127);
  M_bb.gira_horario(127);

  // UI.Update();
  // UI.Draw();

  // Exibir lista de opcoes do menu principal
  // TODO: Controle de rotinas: Definir quanto tempo deve ser alocado para cada tarefa
  // A cada x frames/loops, atualizar UI
  // A cada x frames/loops, chamar update do sistema
  // A cada x frames/loops, enviar os novos comandos para os motores
}