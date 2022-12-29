#pragma once

#include "BoundBlock.h"

class EntityManager {

public:
	~EntityManager();
	std::vector<Entity*> entities;
	std::vector<BoundBlock*> BoundBlocks;
	std::vector<Entity*> ghosts;
	void tick();
	void render();
	void setKillable(bool);
	void setRandomGhostCount(int);
	int getRandomGhostCount();
	int getPlayerX();
	void setPlayerX(int);
	int getPlayerY();
	void setPlayerY(int);
	int getMaxRandomGhosts();
	void setMaxRandomGhosts(int);


	void setPABGhostCount(int);
	int getPABGhostCount();




private:
	bool killable = false;
	int killableCounter;

	int randomGhostCount = 0;
	int maxRandomGhosts = 1;
	int playerX;
	int playerY;
	int PABGhostCount;

};