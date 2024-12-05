#pragma once
#include "WString.h"
#include "wiring_private.h"
#include "LiquidCrystal.h"

#define DEF_REFRESH_RATE_MS 1000

class DisplayDevice
{
    LiquidCrystal* driver;

    unsigned long ms_counter = 0;

    public:
        virtual LiquidCrystal* GetRawDevice();

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
                driver->clear();
            }
        }
};