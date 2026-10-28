#pragma once

#include <iostream>
#include <checkbox.hpp>

class MacCheckbox: public Checkbox
{
    public:
        void paint() { std::cout << "Render a checkbox in MacOS style" << std::endl;};
};