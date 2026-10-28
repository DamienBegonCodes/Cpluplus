#pragma once

#include <win_button.hpp>
#include <win_checkbox.hpp>
#include <ui_elements.hpp>
#include <gui_factory.hpp>

class WinFactory: public GuiFactory
{
    public:
        Button* createButton() {return new WinButton();};
        Checkbox* createCheckbox() {return new WinCheckbox();};
};