#include "Display.h"
#include "LiquidCrystal.h"

#define LCD_WIDTH 2
#define LCD_HEIGHT 2

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
    }

    void Setup()
    {
        driver->begin(LCD_WIDTH, LCD_HEIGHT);
        driver->clear();
        driver->home();
    }

    void Print(const String&s)
    {
        driver->print(s);
    }

    void Clear()
    {
        driver->clear();
        driver->home();
    }
};