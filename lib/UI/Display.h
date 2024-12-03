#pragma once
#include "WString.h"
#include "LiquidCrystal.h"

class DisplayDevice
{
    LiquidCrystal* driver;

    public:
        virtual LiquidCrystal* GetRawDevice();

        virtual void Print(const String&) = 0;
        virtual void PrintLine(const String&) = 0;
        virtual void Clear() = 0;
};