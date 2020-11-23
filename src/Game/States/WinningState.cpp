#include "WinningState.h"

WinningState::WinningState(){
	timer = 500;
	victoryImage.load("images/Victory.png");
	victorySound.load("Sounds/EmptyPlate.wav");
}

void WinningState::tick(){
	timer--;
	if(timer == 0){
		timer = 500;
		if(victorySound.isPlaying()){
			victorySound.stop();
		}
		setNextState("Game");
		setFinished(true);
	}
	if(!victorySound.isPlaying() && getNextState() == ""){
		victorySound.play();
	}
}

void WinningState::render(){
	ofSetColor(255);
	victoryImage.draw(0,0,ofGetWidth(),ofGetHeight());
}

void WinningState::keyPressed(int key){

}

void WinningState::mousePressed(int x, int y, int button){
}

void WinningState::reset(){
	setFinished(false);
	setNextState("");
}

