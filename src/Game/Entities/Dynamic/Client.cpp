#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
    setPatience(2000);
    setRed(ofColor(255,255,255));
}
Client::~Client(){
    burger->~Burger();
}
void Client::render(){
    ofSetColor(255,255,255);
    burger->render();
    switch(getPatience()){
        case 1500:
            setRed(ofColor(255,143,139));
            break;
        case 1000:
            setRed(ofColor(255,69,76));
            break;
        case 500:
            setRed(ofColor(255,0,0));
            break;
    }
    ofSetColor(getRed());
    sprite.draw(x, y, width, height);
    // ofDrawRectangle(getBounds());
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    setPatience(getPatience()-1);
    burger->setY(y);
    if(getPatience() == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    isLeaving = true;
    return 10;
}