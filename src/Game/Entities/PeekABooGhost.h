#pragma once
#include "Ghost.h"
#include "Player.h"

class PeekABooGhost: public Ghost {
        public:
            PeekABooGhost(int, int, int, int, ofImage, EntityManager*, string);
             
            bool isVisible();
            void render();
            void tick();
            void setVisible(bool);
        private:
            bool visible;

};