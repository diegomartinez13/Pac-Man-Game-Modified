#include "GameOverState.h"

GameOverState::GameOverState() {
	MenuButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Menu");
	img1.load("images/pacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void GameOverState::tick() {
	MenuButton->tick();
	anim->tick();
	if(MenuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);

	}
}
void GameOverState::render() {
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, ofGetHeight()/2-200, 50);
    ofDrawBitmapString("GAME OVER", ofGetWidth(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(102, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	MenuButton->render();


}

void GameOverState::keyPressed(int key){
	
}

void GameOverState::mousePressed(int x, int y, int button){
	MenuButton->mousePressed(x, y);
}

void GameOverState::reset(){
	setFinished(false);
	setNextState("");
	MenuButton->reset();
}

void GameOverState::setScore(int sc){
    score = sc;
}

GameOverState::~GameOverState(){
	delete MenuButton;
	delete anim;
}