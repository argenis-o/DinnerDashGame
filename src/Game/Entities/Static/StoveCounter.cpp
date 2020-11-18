#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite): BaseCounter(x,y,width,height,item,sprite){
    alarm.load("sounds/alarm.wav");
    checkMark.load("images/checkMark.png");
    setTimer(TIME_OF_PATTY);
    this->item = item;
}

void StoveCounter::runTimer(){
    setTimer(getTimer()-1);
    if(getTimer() <= 0){
        alarm.play();
    }
    else{
        runTimer();
    }
}

Item* StoveCounter::getItem(){
    if(getTimer() == TIME_OF_PATTY){
        runTimer();
    } 
    else if(item!=nullptr && ( getTimer()==0 )){
        setTimer(TIME_OF_PATTY);
        return item;
    }
    return nullptr;
}

void StoveCounter::showItem(){
    if (item != nullptr && ( getTimer()==TIME_OF_PATTY )){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
    else if(item != nullptr && ( getTimer()<=0 )){
        checkMark.draw(x+width/2 -35, y-120, 120, 120);
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}