#include "WinState.h"

WinState::WinState() {
	back2MenuButton = new Button(ofGetWidth()-widthThrd-40, ofGetHeight()/2, 100, 100, "Go to Menu");
	img1.load("images/pacman.png");
    img2.load("images/youWinPng.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void WinState::tick() {
	back2MenuButton->tick();
	anim->tick();
	if(back2MenuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void WinState::render() {
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()-widthThrd, ofGetHeight()/2-200, 50);
    ofDrawBitmapString("YEII!\n YOU WON!", ofGetWidth()-widthThrd, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0,76,153);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()-widthThrd, ofGetHeight()/2-100, 100, 100);
	back2MenuButton->render();
    img2.draw(0,0);


}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	back2MenuButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	back2MenuButton->reset();
}

void WinState::setScore(int sc){
    score = sc;
}

WinState::~WinState(){
	delete back2MenuButton;
	delete anim;
}