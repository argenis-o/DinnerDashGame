#include "BaseCounter.h"

class StoveCounter: public BaseCounter{
private:
    ofSoundPlayer alarm;
    ofImage checkMark;
    Item* item;
    int timer = 300;
    bool start = false;
public:
    StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);


    void tick();
    Item* getItem();
    void showItem();
    void setTimer(int t){this->timer=t;}
    };
