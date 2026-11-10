#ifndef H_HOUSEBUILDER
#define H_HOUSEBUILDER

class House;

class HouseBuilder
{
private:
    House * house;

public:
    HouseBuilder();
    ~HouseBuilder();
    void reset();
    void build_windows(int nb_windows);
    void build_doors(int nb_doors);
    void build_rooms(int nb_rooms);
    void build_pool(int pool_size);
    void build_garden(int garden_size);
    void build_garage(int garage_size);
    House * get_product();
};

#endif