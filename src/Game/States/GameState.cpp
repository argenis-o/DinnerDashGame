#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
	// background.load("sounds/background.wav");
}
void GameState::tick() {
	restaurant->tick();
	//if(!background.isPlaying()){
	// background.play();
	// }

	if(restaurant->getMoney() == 100){
		setNextState("Win");
		setFinished(true);
		this->restaurant = new Restaurant();
		//if(background.isPlaying()){
		// background.stop();
		// }
	}
	if(restaurant->getLeavingsClients() <= 0 ){
		setNextState("LoseState");
		setFinished(true);
		this->restaurant = new Restaurant();
		//if(background.isPlaying()){
		// background.stop();
		// }
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}