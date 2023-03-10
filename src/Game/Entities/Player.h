#pragma once
#include "Animation.h"

#include "EntityManager.h"
#include "Powerup.h"

class Player: public Entity{

    private:
        int spawnX, spawnY;
        int health=3;
        int score=0;
        bool canMove;
        int speed = 8;
        bool walking = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        Powerup* powerup;
        bool visible;
        
    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        int getHealth();
        void setVisible(bool);
        bool isVisible();
        EntityManager* getEM();
        int getX();
        void setX(int);
        int getY();
        void setY(int);
        void setHealth(int);
        int getScore();
        void setScore(int);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();
        void die();
        int invisibleCounter;
};