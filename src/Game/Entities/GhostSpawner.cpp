#include "GhostSpawner.h"
#include "Ghost.h"
#include "RandomGhost.h"
#include "BigDot.h"
#include "Dot.h"
#include "PeekABooGhost.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height){
    this->em = em;
    this->sprite = sprite;
    spawnGhost("red");
    spawnGhost("pink");
    spawnGhost("cyan");
    spawnGhost("orange");

}

void GhostSpawner::tick(){
    std::vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if(em->ghosts.size()<4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }else{
            spawnCounter--;
        }
    }
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}
void GhostSpawner::spawnRandomGhost(int x, int y){
    int i;
    bool success = false;
    while(!success && em->entities.size() > 0){
            i = ofRandom(em->entities.size());
            if(dynamic_cast<Dot*>(em->entities[i]) || dynamic_cast<BigDot*>(em->entities[i])){
                int coords[2] = {x,y};
                if(RandomGhost::calculateDistance(em->entities[i],coords) > 30){
                    em->entities[i]->remove = true;
                    RandomGhost* g = new RandomGhost(em->entities[i]->getX(),em->entities[i]->getY(),width-2,height-2,sprite,em, "pink");
                    em->ghosts.push_back(g);
                    success = true;
                }
            }
    }
}

void GhostSpawner::spawnPABGhost(){
    PeekABooGhost* g = new PeekABooGhost(x,y,width-2,height-2,sprite,em, "cyan");
    em->ghosts.push_back(g);
}
void GhostSpawner::keyPressed(int key){
    if(key == 'g'){
        spawnGhost(colors[static_cast<int>(ofRandom(4))]);
    }
    if(key == 'r'){
        spawnRandomGhost(em->getPlayerX(),em->getPlayerY());
        em->setMaxRandomGhosts(em->getMaxRandomGhosts()+1);
        em->setRandomGhostCount(em->getRandomGhostCount()+1);
    }
    if(key == 'i'){
        spawnPABGhost();
    }

}