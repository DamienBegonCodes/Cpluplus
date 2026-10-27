#pragma once

#include <button.hpp>

class WindowsButton: public Button
{
    public:
        WindowsButton() {setGreeting("Hi I'm a Windows Button");};
        void render() {std::cout << "Windows Button is now rendered" << std::endl;};

        

};