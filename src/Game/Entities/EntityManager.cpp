#include "EntityManager.h"
#include "Ghost.h"
#include "RandomGhost.h"
#include "PeekABooGhost.h"

void EntityManager::tick(){
    if(killable){
        killableCounter--;
        if (killableCounter == 0){
            killable = false;
            for(Entity* entity:ghosts){
                Ghost* ghost = dynamic_cast<Ghost*>(entity); 
                ghost->setKillable(false);
            }
        }
    }
    std::vector<int> toRemove;
    
    for(int i=0;i<entities.size();i++){
        if(!entities[i]->remove){
            entities[i]->tick();

        }else{
            toRemove.push_back(i);
        }
    }
    for(unsigned int removable: toRemove){
        Entity* entityPointer = *(entities.begin() + removable);
        entities.erase(entities.begin() + removable);
        delete entityPointer;
    }
    toRemove.clear();
    for(BoundBlock* BoundBlock: BoundBlocks){
        BoundBlock->tick();
    }
    for(int i=0;i<ghosts.size();i++){
        if(!ghosts[i]->remove){
            ghosts[i]->tick();

        }else{
            toRemove.push_back(i);
        }
    }
    for(unsigned int removable: toRemove){
        Ghost* entityPointer = dynamic_cast<Ghost*>(*(ghosts.begin() + removable));
        ghosts.erase(ghosts.begin() + removable);
        delete entityPointer;
    }
}

void EntityManager::render(){
    for(Entity* entity: entities){
        entity->render();
    }
    for(BoundBlock* BoundBlock: BoundBlocks){
        BoundBlock->render();
    }
    for(Entity* ghost: ghosts){
        ghost->render();
    }
}

void EntityManager::setKillable(bool k){
    killable = true;
    killableCounter=30*10;
    for(Entity* entity:ghosts){
        Ghost* ghost = dynamic_cast<Ghost*>(entity); 
        ghost->setKillable(true);
    }
}

int EntityManager::getRandomGhostCount(){
        return randomGhostCount;
}

void EntityManager::setRandomGhostCount(int count){
    this->randomGhostCount = count;
}

void EntityManager::setPlayerX(int x){this->playerX = x;}

int EntityManager::getPlayerX(){return playerX;}

void EntityManager::setPlayerY(int y){this->playerY = y;}

int EntityManager::getPlayerY() {return playerY;}

int EntityManager::getMaxRandomGhosts() {return maxRandomGhosts;}

void EntityManager::setMaxRandomGhosts(int newmax){maxRandomGhosts = newmax;}

int EntityManager::getPABGhostCount(){
        return PABGhostCount;
}

void EntityManager::setPABGhostCount(int count){
    this->PABGhostCount = count;
}



EntityManager::~EntityManager(){
    for(Entity* e: BoundBlocks){
        delete e;

    }
    for(Entity* e: ghosts){
        Ghost* ghostPointer = dynamic_cast<Ghost*>(e);
        delete ghostPointer;
    }
    for(Entity* e: entities){
        delete e;
    }
    BoundBlocks.clear();
    ghosts.clear();
    entities.clear();
}

