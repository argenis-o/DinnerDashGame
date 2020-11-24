#pragma once
#include "State.h"
#include "Restaurant.h"

class GameState: public State{
    public: 
        GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		ofSoundPlayer background;
	
	private:
		Restaurant *restaurant;
};
