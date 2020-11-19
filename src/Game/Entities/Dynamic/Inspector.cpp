#include "Inspector.h"
Inspector::Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger): Client(x,y,width,height,sprite,burger){
    this->burger = burger;
}
Inspector::~Inspector(){
    burger->~Burger();
}
void Inspector::render(){
    ofSetColor(255,255,255);
    burger->render();
    switch(getPatience()){
        case 1500:
            setRed((255,143,139));
            break;
        case 1000:
            setRed((255,69,76));
            break;
        case 500:
            setRed((255,0,0));
            break;
    }
    ofSetColor(getRed());
    sprite.draw(x, y, width, height);
    // ofDrawRectangle(getBounds());
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Inspector::tick(){
    setPatience(getPatience()-1);
    burger->setY(y);
    if(getPatience() == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Inspector::serve(Burger* burger){
    isLeaving = true;
    return 15;
}