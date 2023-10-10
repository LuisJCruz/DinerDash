#include "LoseState.h"

LoseState::LoseState() {
	gameOver.load("images/fotogameover.png");
	instructions = "Press SPACE to return to the main menu";
	
	
	
}
void LoseState::initItems(){
    gameOver.cropFrom(gameOver,-5,28,112,50);
}
void LoseState::tick() {
	
}
void LoseState::render() {
	ofSetBackgroundColor(255, 0, 0);
	ofSetColor(0, 0, 0);
    ofDrawBitmapString(instructions, 250, 400);
	ofDrawBitmapString(instructions2, 100, 10);
	gameOver.draw(0,0,ofGetWidth(),ofGetHeight());
    
}

void LoseState::keyPressed(int key){
	if (key==' '){
        setNextState("Menu");
        setFinished(true);
    }
}

void LoseState::mousePressed(int x, int y, int button){
	
}

void LoseState::reset(){
	
}
