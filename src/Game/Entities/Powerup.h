#pragma once
#include "ofMain.h"
#include "Entity.h"

class Powerup {
    protected:
        bool usable;
        string powerupname;
    public:
        bool isUsable(){
            return usable;
        };
        virtual void activate(Entity*) = 0;
};