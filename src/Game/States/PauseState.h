#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h"
class PauseState : public State {
private:
	ofImage img1;
    ofImage img2;
	Button *ResumeButton;
    Button *QuitButton;
	Animation* anim;
    int score=0;
    int widthThrd = ofGetWidth()/3;
    
public:
	PauseState();
	~PauseState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
    void setScore(int);

};
