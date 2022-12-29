#pragma once
#include "ofMain.h"
#include "Powerup.h"
#include "Entity.h"
class InvisiblePowerUp: public Powerup {
    protected:
        bool usable;
        string powerupname = "Invisible";

    public:
        InvisiblePowerUp(bool);
        void activate(Entity*);

};
