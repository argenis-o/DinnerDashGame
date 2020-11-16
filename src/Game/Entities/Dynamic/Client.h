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
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;

        Burger* getBurger(){return burger;}

        int getPatience(){return patience;}
        void setPatience(int patience){this->patience = patience;}
        
        ofColor getRed(){return this->red;}
        void setRed(ofColor red){this->red.set(red);}


};