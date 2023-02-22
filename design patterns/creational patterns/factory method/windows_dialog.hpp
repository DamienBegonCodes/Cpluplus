#pragma once

#include <dialog.hpp>
#include <windows_button.hpp>

class WindowsDialog: public Dialog
{
    public:
        Button* createButton() {return new WindowsButton();};
};