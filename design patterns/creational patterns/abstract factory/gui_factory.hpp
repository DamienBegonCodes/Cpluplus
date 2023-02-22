#pragma once

#include <ui_elements.hpp>

class GuiFactory
{
    public:
        virtual Button* createButton() = 0;
        virtual Checkbox* createCheckbox() = 0;
};