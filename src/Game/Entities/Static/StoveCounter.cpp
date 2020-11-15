#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite): BaseCounter(x,y,width,height,item,sprite){
    alarm.load("sounds/alarm.wav");
    checkMark.load("images/checkMark.png");
    setTimer(this->TIME_OF_PATTY);
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
    while(getTimer() == 0){
        //Puede recoger el patty y verlo display
        showItem();
    }
}