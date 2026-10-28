#pragma once

#include <iostream>
#include <button.hpp>

class WinButton: public Button
{
    public:
        void paint() {std::cout << "Render a button in Windows style" << std::endl;};
};