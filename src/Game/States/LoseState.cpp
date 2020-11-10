#include "LoseState.h"

LoseState::LoseState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Play again");
}
void LoseState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void LoseState::render() {
	ofSetBackgroundColor(230, 230, 250);
	startButton->render();
}

void LoseState::keyPressed(int key){
	
}

void LoseState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}