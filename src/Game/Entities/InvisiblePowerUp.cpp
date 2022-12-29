#pragma once
#include "InvisiblePowerUp.h"
#include "Dot.h"
#include "BigDot.h"
#include "Player.h"
InvisiblePowerUp::InvisiblePowerUp(bool usable){
    this->usable = usable;
}
void InvisiblePowerUp::activate(Entity* e){
    Player *p = dynamic_cast<Player*>(e);
    if (!usable || p == nullptr) return;
    p->setVisible(false);
    p->invisibleCounter = 90;
    this->usable = false;
}