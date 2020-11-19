#include "WinningState.h"

WinningState::WinningState(){
    replayButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Play Again");
}

void WinningState::tick(){
    replayButton->tick();
	if(replayButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}

void WinningState::render(){
    ofSetBackgroundColor(ofColor::yellow);
    ofDrawBitmapStringHighlight("Temporary State", ofGetWidth()/2, ofGetHeight()/2 - 150, ofColor::gray, ofColor::limeGreen);
	replayButton->render();
}

void WinningState::keyPressed(int key){

}

void WinningState::mousePressed(int x, int y, int button){
    replayButton->mousePressed(x,y);
}

void WinningState::reset(){
	setFinished(false);
	setNextState("");
	replayButton->reset();
}

