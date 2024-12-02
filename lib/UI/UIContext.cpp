#include "UIContext.h"

UIContext& UIContext::GetInstance()
{
    static UIContext self_;

    return self_;
}