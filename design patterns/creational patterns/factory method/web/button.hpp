#pragma once

#include <memory>
#include <string>
#include <iostream>

class Button
{
    protected:
        std::string greeting;

    public:
        virtual void setGreeting(std::string s) {greeting = s;};
        virtual void render() = 0;
        virtual void onClick() {std::cout << greeting << std::endl;};
        Button() = default;
        virtual ~Button() {};
        
};