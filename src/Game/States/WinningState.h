#pragma once

#include "State.h"

class WinningState: public State{
    public: 
        WinningState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
	private:
		ofImage victoryImage;
		int timer;
		ofSoundPlayer victorySound;
};
