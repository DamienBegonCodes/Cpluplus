#pragma once

#include <button.hpp>
#include <iostream>

class MacButton: public Button
{
    public:
        void paint() {std::cout << "Render a button in MacOS style" << std::endl;};
};
