#include "WString.h"

class DisplayDevice
{
    public:
        virtual void Print(const String&) = 0;
        virtual void Clear() = 0;
};

class Display
{
    DisplayDevice* display_device = nullptr;

    Display(DisplayDevice* device)
    {
        this->display_device = device;
    }

    void Print(const String& s)
    {
        display_device->Print(s);
    }

    void Clear()
    {
        display_device->Clear();
    };
};
