#include "LoseState.h"

LoseState::LoseState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Play again");
	img1.load("images/WhatAreYou.png");
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

	ofSetColor(255);
	img1.draw(0,0,ofGetWidth(),ofGetHeight());

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