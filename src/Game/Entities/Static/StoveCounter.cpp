#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite): BaseCounter(x,y,width,height,item,sprite){
    alarm.load("sounds/alarm.wav");
    checkMark.load("images/checkMark.png");
    setTimer(this->TIME_OF_PATTY);
    this->item = item;
}

void StoveCounter::runTimer(){
    setTimer(getTimer()-1);
    if(getTimer() == 0){
        alarm.play();
    }
    else{
        runTimer();
    }
}

void StoveCounter::cook(){
    runTimer();
    while(getTimer() == 0){// to show the item the time that the player dont get the patty
        checkMark.draw(x+width/2 -25, y-80, 50, 30);
        showItem();
    }
}
void StoveCounter::render(){
    if(item != nullptr && item->name == "patty"){
        cook();
    }
}