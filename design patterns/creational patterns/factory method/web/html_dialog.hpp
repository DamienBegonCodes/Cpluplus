#pragma once

#include <dialog.hpp>
#include <html_button.hpp>

class HtmlDialog: public Dialog
{
    public:
        Button* createButton() {return new HtmlButton();};       
};