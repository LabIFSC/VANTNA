#pragma once
#include "WString.h"
#include "wiring_private.h"
#include "LiquidCrystal.h"

#define DEF_REFRESH_RATE_MS 1000

class IRefreshable
{
    protected:
        unsigned long ms_counter = 0;

    public:

        /**
         * Clears the screen at specified `refresh_rate` interval in ms.
         * Default: `1000ms`
         */
        virtual void Refresh(unsigned long ms = DEF_REFRESH_RATE_MS) = 0;
};