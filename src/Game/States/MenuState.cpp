#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(ofGetWidth()/2 -80, ofGetHeight()/2+20, 364, 350, "\n");
	title.load("images/title.jpg");
	img1.load("images/START.png");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetColor(255);
	title.draw(0,0,ofGetWidth(),ofGetHeight());
	img1.draw(ofGetWidth()/2-160, ofGetHeight()/2-20, 364, 350);
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}
