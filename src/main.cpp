//////
#include <Arduino.h>
#include <Motor.h>
#include "Bussola.h"
#include "LED.h"
#include "GPS.h"
#include "UIContext.h"

#define HBRIDGE_5V A1

/** Init dispositivos e periféricos */

// Cria os objetos motor1 e motor2 utilizando o construtor Motor(pin1 , pin2, enable)
Motor M1(PIN7, PIN6, PIN3); /** In1 | In2 | EnableA */
Motor M2(PIN5, PIN4, PIN2); /** In3 | In4 | EnableB */

Bussola B;
GPS GPS_A;

static UIContext UI;

void setup() 
{
  /** Inicializar subsistemas */
  M1.setup();
  M2.setup();

  B.setUp();
  GPS_A.setUp();

  // - Display LCD (IO)
  // - Teclado (IO)
}

void loop() 
{
  UI.GetRawDisplay()->Print("Rodou");
  delay(1000);
  UI.GetRawDisplay()->Clear();

  // TODO: Ouvir por chamadas através dos botões para funções especificadas
  // callbacks[buttons] = { [MENU_A] = enviar_coordenadas(...) }
}