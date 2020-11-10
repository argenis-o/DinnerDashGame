#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
<<<<<<< HEAD

	if(restaurant->getMoney() == 100){
		setNextState("Win");
=======
	}
	if(restaurant->getLeavingsClients() <= 0 ){
		setNextState("LoseState");
>>>>>>> addLoseState
		setFinished(true);
		this->restaurant = new Restaurant();
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