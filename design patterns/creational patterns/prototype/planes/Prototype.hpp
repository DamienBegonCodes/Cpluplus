#ifndef H_PROTOTYPE
#define H_PROTOTYPE

#include <string>

class Prototype
{
public:
    virtual Prototype * clone() = 0;
    virtual std::string to_string() = 0;
    virtual ~Prototype() {};
};

#endif