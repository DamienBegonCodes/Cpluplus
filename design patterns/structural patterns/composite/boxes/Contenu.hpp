#ifndef H_CONTENU
#define H_CONTENU

class Contenu
{
protected:
    float ownWeight;
public:
    virtual ~Contenu() {};
    virtual int countProducts() = 0;
    virtual float getWeight() = 0;
};

#endif