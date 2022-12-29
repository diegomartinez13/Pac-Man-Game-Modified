#include "PauseState.h"

PauseState::PauseState() {
	ResumeButton = new Button(ofGetWidth()-widthThrd-40, ofGetHeight()/2, 100, 100, "RESUME");
   	QuitButton = new Button(ofGetWidth()-widthThrd+100, ofGetHeight()/2, 100, 100, "QUIT");
	img1.load("images/pacman.png");
    img2.load("images/pause.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void PauseState::tick() {
	ResumeButton->tick();
    QuitButton->tick();
	anim->tick();
	if(ResumeButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
    if(QuitButton->wasPressed()){
        setNextState("Menu");
        setFinished(true);
    }
}
void PauseState::render() {
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()-widthThrd, ofGetHeight()/2-200, 50);
    ofDrawBitmapString("GAME PAUSED", ofGetWidth()-widthThrd, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(160, 160, 160);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()-widthThrd, ofGetHeight()/2-100, 100, 100);
	ResumeButton->render();
    QuitButton->render();
    img2.resize(481,481);
    img2.draw(0,0);


}

void PauseState::keyPressed(int key){
	
}

void PauseState::mousePressed(int x, int y, int button){
	ResumeButton->mousePressed(x, y);
    QuitButton->mousePressed(x,y);
}

void PauseState::reset(){
	setFinished(false);
	setNextState("");
	ResumeButton->reset();
    QuitButton->reset();
}

void PauseState::setScore(int sc){
    score = sc;
}

PauseState::~PauseState(){
    delete QuitButton;
	delete ResumeButton;
	delete anim;
}