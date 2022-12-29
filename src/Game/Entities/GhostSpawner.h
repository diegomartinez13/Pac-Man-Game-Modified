#pragma once

#include "EntityManager.h"
#include "Player.h"
class GhostSpawner: public Entity{
    public:
        GhostSpawner(int, int, int , int, EntityManager*, ofImage);
        void spawnGhost(string);
        void spawnRandomGhost(int,int);
        void spawnPABGhost();
        void keyPressed(int);
        void tick();
    private:
        EntityManager* em;
        int spawnCounter = 30*5;
        string colors[4] = {"red","pink","cyan","orange"} ;
};