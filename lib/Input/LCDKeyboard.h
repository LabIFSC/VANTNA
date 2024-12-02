#pragma once

#define BTN_NONE   0
#define BTN_SELECT 1
#define BTN_LEFT   2
#define BTN_UP     3
#define BTN_DOWN   4
#define BTN_RIGHT  5

#define DEBOUNCE_TIMER 50

typedef unsigned char BTN_ID;

enum BTN_STATE { PRESSED, NOT_PRESSED };

/**
 * Driver específico para o teclado integrado no projeto
 * TODO: Adicionar modelo do componente
 */
class LCDKeyboard
{
  BTN_ID states[6] = {};

  public:
  void SetState(unsigned char btn, BTN_STATE state);
  bool IsBtnDown(BTN_ID id);

  void PoolEvents()
  {
    //
  }
};