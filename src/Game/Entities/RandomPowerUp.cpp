#pragma once
#include "RandomPowerUp.h"
#include "Dot.h"
#include "BigDot.h"
#include "Player.h"
RandomPowerUp::RandomPowerUp(bool usable){
    this->usable = usable;
}
void RandomPowerUp::activate(Entity* e){
    Player *p = dynamic_cast<Player*>(e);
    if (!usable || p == nullptr) return;
    int i;
    bool success = false;
    while(!success && p->getEM()->entities.size() > 0){
            i = ofRandom(p->getEM()->entities.size());
            if(dynamic_cast<Dot*>(p->getEM()->entities[i]) || dynamic_cast<BigDot*>(p->getEM()->entities[i])){
                    p->setX(p->getEM()->entities[i]->getX());
                    p->setY(p->getEM()->entities[i]->getY());
                    success = true;
            }
    }
    this->usable = false;
}
