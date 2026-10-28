#pragma once

#include <gui_factory.hpp>
#include <mac_button.hpp>
#include <mac_checkbox.hpp>
#include <ui_elements.hpp>

class MacFactory: public GuiFactory
{
    public:
        Button* createButton() { return new MacButton();};
        Checkbox* createCheckbox() { return new MacCheckbox();};
};