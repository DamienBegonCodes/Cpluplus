#ifndef H_COFFEETABLE
#define H_COFFEETABLE

#include <string>

class CoffeeTable
{
protected:
    int plate_length;
    int plate_width;
public:
    virtual std::string plate_shape() = 0;
    virtual ~CoffeeTable() {};
};

#endif