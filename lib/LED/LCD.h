#include "Display.h"

#define LCD_WIDTH 0x0F
#define LCD_HEIGHT 0x02

//******* CONFIGURACAO DO LCD *********
#define PIN_Botoes A0

#define PIN_RS 8
#define PIN_EN 9
#define PIN_D4 4
#define PIN_D5 5
#define PIN_D6 6
#define PIN_D7 7
#define PIN_BACKLIGHT 10
//*****************************************

class LCD : public DisplayDevice
{
    LiquidCrystal* driver;

    public:
    LCD()
    {
        driver = new LiquidCrystal(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7);
        Setup();
    }

    void Setup()
    {
        driver->begin(LCD_WIDTH, LCD_HEIGHT);
        driver->noAutoscroll();
        driver->clear();
    }

    LiquidCrystal* GetRawDevice()
    {
        return driver;
    }

    void Print(const String&s)
    {
        driver->print(s);
    }

    void PrintLine(const String&s)
    {
        driver->println(s);
    }

    void Clear()
    {
        driver->clear();
        driver->home();
    }
};