#include "Display.h"

#define LCD_WIDTH 0x0F
#define LCD_HEIGHT 0x02

struct LCDSettings
{
  uint8_t pin_rs;
  uint8_t pin_es;
  uint8_t pin_d4;
  uint8_t pin_d5;
  uint8_t pin_d6;
  uint8_t pin_d7;
  uint8_t pin_backlight;
};

class LCD : public LiquidCrystal, public IRefreshable
{
    public:
    LCD(LCDSettings settings) :
        LiquidCrystal(settings.pin_rs, settings.pin_es, settings.pin_d4, settings.pin_d5, settings.pin_d6, settings.pin_d7)
    {
        Setup();
    }

    void Setup()
    {
        begin(LCD_WIDTH, LCD_HEIGHT);
        noAutoscroll();
        clear();
    }

    /**
     * Clears the screen at specified `refresh_rate` interval in ms.
     * Default: `1000ms`
     */
    void Refresh(unsigned long ms = DEF_REFRESH_RATE_MS)
    {
        ms_counter++;
        
        if(ms_counter >= ms)
        {
            ms_counter = 0;
            clear();
        }
    }
};