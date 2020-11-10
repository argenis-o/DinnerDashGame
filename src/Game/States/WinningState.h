#pragma once

#include "State.h"
#include "Button.h"


class WinningState: public State{
    public: 
        WinningState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
	
	private:
		//ofImage victory;
        Button *replayButton;
};