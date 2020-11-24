#pragma once
#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        int patience;
        ofColor red;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        ~Client();
        virtual void tick();
        virtual void render();
        virtual int serve(Burger*, Client*);
        Client* nextClient=nullptr;
        bool isLeaving=false;

        Burger* getBurger(){return burger;}

        int getPatience(){return patience;}
        void setPatience(int patience){this->patience = patience;}
        
        ofColor getRed(){return this->red;}
        void setRed(ofColor red){this->red.set(red);}

        bool getIsLeaving(){return isLeaving;}
};
