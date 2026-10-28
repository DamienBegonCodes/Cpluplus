#ifndef H_CHAIR
#define H_CHAIR

class Chair
{
public:
    int length;
    int height;
    int breadth;

    virtual bool has_legs() = 0;
    virtual ~Chair() {};
};

#endif