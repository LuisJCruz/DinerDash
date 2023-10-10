#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	instructions = "Pick ingredients with letter 'e' when the player is in front of the counter";
	instructions2 = "Serve clients with letter 's'";
	instructions3 = "Undo the ingredient with letter 'u'";
	instructions4 = "Move the chef with '<' and '>'" ;
	
	
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	img1.load("images/pixelburgrtitlescreen.jpg");
	img1.draw(0, 0, ofGetWidth(),ofGetHeight());
	startButton->render();
	ofSetColor(255);
    ofDrawBitmapString(instructions, 100, 80);
	ofDrawBitmapString(instructions2, 100, 100);
	ofDrawBitmapString(instructions3, 100, 120);
	ofDrawBitmapString(instructions4, 100, 140);
    ofSetColor(256, 256, 256);
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}