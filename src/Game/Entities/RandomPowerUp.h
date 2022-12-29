#pragma once
#include "ofMain.h"
#include "Powerup.h"
#include "Entity.h"
class RandomPowerUp: public Powerup {
    protected:
        bool usable;
        string powerupname = "Random";
    public:
        RandomPowerUp(bool);
        void activate(Entity*);
};