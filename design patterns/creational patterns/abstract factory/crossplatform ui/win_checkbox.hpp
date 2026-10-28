#pragma once

#include <iostream>
#include <checkbox.hpp>


class WinCheckbox: public Checkbox
{  
    public:
        void paint() {std::cout << "Render a checkbox in Windows style" << std::endl;};
};