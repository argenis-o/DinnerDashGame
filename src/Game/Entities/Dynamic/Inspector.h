#pragma once
#include "Client.h"


class Inspector: public Client
{
private:
    Burger* burger;
public:
    Inspector(int,int,int,int,ofImage,Burger*);
    ~Inspector();
    void tick();
    void render();
    int serve(Burger*);
};
