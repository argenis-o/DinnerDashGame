#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite): BaseCounter(x,y,width,height,item,sprite){
    alarm.load("sounds/alarm.wav");
    checkMark.load("images/checkMark.png");
    this->item = item;
}

void StoveCounter::tick(){
    if(start){
        if(timer>0){
            timer--;
        }
        else{
            getItem();
            alarm.play();
            start = false;

        }
    }
}

Item* StoveCounter::getItem(){
    start = true;
    if(timer != 0){return nullptr;}
    return item;
}

void StoveCounter::showItem(){
    if (item != nullptr && (timer == 300 )){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
    else if(item != nullptr && ( timer == 0)){
        checkMark.draw(x+width/2 -35, y-120, 120, 120);
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}
