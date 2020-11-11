#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    burger->~Burger();
}
void Client::render(){
    ofSetColor(255,255,255);
    burger->render();
    switch(patience){
        case 1500:
            red = ofColor(255,143,139);
            break;
        case 1000:
            red = ofColor(255,69,76);
            break;
        case 500:
            red = ofColor(255,0,0);
            break;
    }
    ofSetColor(red);
    sprite.draw(x, y, width, height);
    // ofDrawRectangle(getBounds());
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
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