#pragma once

#include <button.hpp>

class Dialog
{
    public:
        void render()
        {
            Button* b = createButton();
            b->onClick();
            b->render();
        }
        virtual Button* createButton() = 0;
        ~Dialog() {};
};