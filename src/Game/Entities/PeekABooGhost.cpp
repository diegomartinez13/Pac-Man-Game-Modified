
#pragma once
#include "PeekABooGhost.h"
#include "Dot.h"
#include "BigDot.h"
#include <math.h>
#include "GhostSpawner.h"
PeekABooGhost::PeekABooGhost( int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em, string color): 
    Ghost(x, y, width, height,spriteSheet,em,color)
    {
    

}

bool PeekABooGhost::isVisible(){
    return visible;
}

void PeekABooGhost::setVisible(bool v){
    this->visible = v;
}

void PeekABooGhost::render(){
    if(visible){
        Ghost::render();
    }
}

void PeekABooGhost::tick(){
    int coords[2] = {em->getPlayerX(),em->getPlayerY()};
    if (Ghost::calculateDistance(this,coords) < 75){
        this->visible = true;
    } else {
        this->visible = false;
    }
    Ghost::tick();
}