#pragma once

#include "Entity.h"
#include "Client.h"

class EntityManager {
private:
int loseGame = 1;
public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
	int getLoseGame(){return this->loseGame;}
	void setLoseGame(int loseGame){ this->loseGame = loseGame;}
};