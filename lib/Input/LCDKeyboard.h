#pragma once
#include "Arduino.h"

#define BTN_NONE   0
#define BTN_SELECT 1
#define BTN_LEFT   2
#define BTN_UP     3
#define BTN_DOWN   4
#define BTN_RIGHT  5

#define DEBOUNCE_TIMER 500

typedef unsigned char BTN_ID;

enum BTN_STATE { PRESSED, NOT_PRESSED };

/**
 * Driver específico para o teclado integrado no projeto
 * TODO: Adicionar modelo do componente
 */
class LCDKeyboard
{
  uint8_t inputPin_ = 0;

  unsigned long deltaTime = 0;
  BTN_ID previous_frame_btn = BTN_NONE;     // Does not support multiple button presses at same time

  public:

    /**
     * `in_pin` MUST be an analog input. Default `A0`
     */
    LCDKeyboard(uint8_t in_pin = A0)
    {
      inputPin_ = in_pin;
    }

    void SetState(BTN_ID btn)
    {
      previous_frame_btn = btn;
    }

    bool IsBtnDown(BTN_ID id)
    {
      return previous_frame_btn == id;
    }
    void PoolEvents()
    {
      int value = analogRead(inputPin_);

      if((millis() - deltaTime) < DEBOUNCE_TIMER)
        return;

      // Parse button from value
      BTN_ID btn_id;

      if(value >= 1015 && value <= 1025) btn_id = BTN_NONE;
      if(value >= 300 && value <= 310) btn_id = BTN_DOWN;
      if(value >= 125 && value <= 135) btn_id = BTN_UP;
      if(value >= 715 && value <= 725) btn_id = BTN_SELECT;

      if(previous_frame_btn == BTN_NONE && btn_id != BTN_NONE)
      {
        // OnKeypress Callback?
      }

      if(previous_frame_btn != btn_id)
        SetState(btn_id);

      deltaTime = millis();

      if(btn_id == BTN_NONE)
      {
        // TODO: BTN_RELEASED event
      }
  }
};