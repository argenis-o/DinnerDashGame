#include "PauseState.h"
#include "GameState.h"

PauseState::PauseState() {
	Pause.load("images/Pause.png");
}

void PauseState::tick() {
}

void PauseState::render() {
	ofSetColor(255);
	Pause.draw(0,0,ofGetWidth(),ofGetHeight());
}

void PauseState::keyPressed(int key){
	if(key == ' '){
        setNextState("Game");
		setFinished(true);
    }
}

void PauseState::mousePressed(int x, int y, int button){
}

void PauseState::reset(){
	setFinished(false);
	setNextState("");
}
