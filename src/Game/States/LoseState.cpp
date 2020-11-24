#include "LoseState.h"

LoseState::LoseState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 364, 350, "\n");
	img1.load("images/WhatAreYou.png");
	background.load("Sounds/WhatAreYouclip.wav");
	letter.load("images/PlayAgain.png");
}
void LoseState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
	if(!background.isPlaying() && (getNextState() == "") ){
		background.play();
	}
}
void LoseState::render() {
	ofSetBackgroundColor(230, 230, 250);

	ofSetColor(255);
	img1.draw(0,0,ofGetWidth(),ofGetHeight());
	letter.draw(ofGetWidth()/2, ofGetHeight()/2, 364, 350);

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