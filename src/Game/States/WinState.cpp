#include "WinState.h"

WinState::WinState() {
    youWin.load("images/winImage.png");
	instructions = "Press SPACE to return to the main menu";


}
void WinState::initItems(){
    youWin.cropFrom(youWin,-5,28,112,50);
}

void WinState::tick() {

}
void WinState::render() {
	ofSetBackgroundColor(127, 255, 0);
	ofSetColor(0, 0, 0);
    ofDrawBitmapString(instructions, 250, 430);
	ofDrawBitmapString(instructions2, 100, 100);
    youWin.draw(0,0,ofGetWidth(),ofGetHeight());
}

void WinState::keyPressed(int key){
	if (key==' '){
        setNextState("Menu");
        setFinished(true);
    }
}

void WinState::mousePressed(int x, int y, int button){
	
}

void WinState::reset(){
	
}
