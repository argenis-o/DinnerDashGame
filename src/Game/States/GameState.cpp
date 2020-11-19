#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant(0);
	background.load("Sounds/background.wav");
}

void GameState::tick() {
	restaurant->tick();

	if(!background.isPlaying() && (getNextState() == "") ){
		background.play();
	}

	if(restaurant->getMoney() == 100){
		setNextState("Win");
		setFinished(true);
		this->restaurant->setLevel(this->restaurant->getLevel()+1);
		this->restaurant = new Restaurant(this->restaurant->getLevel());
		if(background.isPlaying()){
			background.stop();
		}
	}

	if(restaurant->getLeavingsClients() <= 0 ){
		setNextState("LoseState");
		setFinished(true);
		if(this->restaurant->getLevel() == 0){
			this->restaurant = new Restaurant(this->restaurant->getLevel());	
		}
		else{
			this->restaurant->setLevel(this->restaurant->getLevel()-1);
			this->restaurant = new Restaurant(this->restaurant->getLevel());
		}
		if(background.isPlaying()){
			background.stop();
		}
	}
}

void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	if(key == ' '){
		if(background.isPlaying()){
			background.stop();
		}
        setNextState("Pause");
		setFinished(true);
    }
	else{
		restaurant->keyPressed(key);
	}
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}