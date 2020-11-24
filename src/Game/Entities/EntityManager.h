#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {
private:
	int loseGame = 10;
	int patience;
	bool badReview = false;
public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
	int getLoseGame(){return loseGame;}
	bool getReview(){return this->badReview;}
	void setReview(){this->badReview = !this->badReview;}
};
