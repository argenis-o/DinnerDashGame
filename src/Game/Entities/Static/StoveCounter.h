#include "BaseCounter.h"

class StoveCounter: public BaseCounter{
private:
    ofSoundPlayer alarm;
    ofImage checkMark;
    int timer;
    const int TIME_OF_PATTY = 10000;
    Item* item;
public:
    StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
    int getTimer(){return this->timer;}
    void setTimer(int timer){this->timer = timer;}
    void runTimer();

    Item* getItem();
    void showItem();
    };