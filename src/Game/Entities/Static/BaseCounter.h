 //
// Created by joshu on 11/3/2020.
//

#ifndef APGAMEENGINE_BASECOUNTER_H
#define APGAMEENGINE_BASECOUNTER_H
#include "Item.h"
#include "Entity.h"

class BaseCounter: public Entity {
    private:
        Item *item;
        int timer;

    public:
        BaseCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        virtual Item* getItem();
        virtual void showItem();
        virtual void tick();

        virtual void setTimer(int t){this->timer = t;}



};
#endif //APGAMEENGINE_BASECOUNTER_H
