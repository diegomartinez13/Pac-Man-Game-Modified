#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 
class WinState : public State {
    private:
        ofImage img1;
        ofImage img2;
        Button *back2MenuButton;
        Animation* anim;
        int score=0;
        int widthThrd = ofGetWidth()/3;
    public:
        WinState();
        ~WinState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        void setScore(int);
};
