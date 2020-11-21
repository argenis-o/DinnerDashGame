#include "WinningState.h"

WinningState::WinningState(){
	timer = 500;
	victoryImage.load("images/Victory.png");
	// victorySound.load("Sounds/victorySounds.wav");
}

void WinningState::tick(){
	timer--;
	if(timer == 0){
		timer = 500;
		// if(victorySound.isPlaying()){
		// 	victorySound.stop();
		// }
		setNextState("Game");
		setFinished(true);
	}
	// if(!victorySound.isPlaying() && getNextState() == ""){
	// 	victorySound.play();
	// }
}

void WinningState::render(){
    // ofSetBackgroundColor(ofColor::yellow);
    // ofDrawBitmapStringHighlight("Timer: " + to_string(timer), ofGetWidth()/2, ofGetHeight()/2 - 150, ofColor::gray, ofColor::limeGreen);
	ofSetColor(255);
	victoryImage.draw(0,0,ofGetWidth(),ofGetHeight());
	ofSetBackgroundColor(ofColor::yellow);
    ofDrawBitmapStringHighlight("Timer: " + to_string(timer), ofGetWidth()/2, ofGetHeight()/2 - 150, ofColor::gray, ofColor::limeGreen);
}

void WinningState::keyPressed(int key){

}

void WinningState::mousePressed(int x, int y, int button){
}

void WinningState::reset(){
	setFinished(false);
	setNextState("");
}

