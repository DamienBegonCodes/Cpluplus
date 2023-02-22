#pragma once

#include <button.hpp>

class HtmlButton: public Button
{
    public:
        HtmlButton() {setGreeting("Hi I'm a HTML Button");};
        void render() {std::cout << "HTML Button is now rendered" << std::endl;};
};