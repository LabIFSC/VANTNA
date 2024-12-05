#pragma once
#include "WString.h"
#include "wiring_private.h"
#include "LiquidCrystal.h"

class DisplayDevice
{
    LiquidCrystal* driver;
    unsigned long default_refresh_rate = 1000;

    public:
        virtual LiquidCrystal* GetRawDevice();

        /**
         * Clears the screen at specified `refresh_rate` interval in ms.
         * Default: `1000ms`
         */
        void Refresh(unsigned long ms = 1000)
        {
            unsigned long freq = default_refresh_rate;
            if(ms != 1000)
                freq = ms;

            delay(freq);
            driver->clear();
        }
};