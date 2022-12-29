#pragma once
#include "Ghost.h"
#include "Player.h"

class RandomGhost: public Ghost {
        public:
            RandomGhost(int, int, int, int, ofImage, EntityManager*, string);
        
};