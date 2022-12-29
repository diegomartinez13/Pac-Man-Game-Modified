#include "GameState.h"
#include "Entity.h"
#include "RandomGhost.h"
#include "PeekABooGhost.h"

GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
	
}
void GameState::tick() {
	if(!music.isPlaying()){
			music.play();
	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	if(yPressed || map->getEM()->entities.size() == 0){
		yPressed = false;
		setFinished(true);
		setNextState("win");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
	}
	if (map->getPlayer()->getScore() >= 500 && map->getEM()->getRandomGhostCount() < map->getEM()->getMaxRandomGhosts()){
		map->getGhostSpawner()->spawnRandomGhost(map->getPlayer()->getX(),map->getPlayer()->getY());
		map->getEM()->setRandomGhostCount(map->getEM()->getRandomGhostCount()+1);

	}
	if(pPressed){
		pPressed = false;
		setFinished(true);
		setNextState("Pause");
		finalScore = map->getPlayer()->getScore();
	}
	if (map->getPlayer()->getScore() >= 1000 && map->getEM()->getPABGhostCount() < 1){
		map->getGhostSpawner()->spawnPABGhost();
		map->getEM()->setPABGhostCount(map->getEM()->getPABGhostCount()+1);

	}

}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	if(key == 'y'){yPressed = true;}
	if(key == 'p'){pPressed = true;}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	
	map = MapBuilder().createMap(mapImage);
	setFinished(false);
	setNextState("");
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}