#pragma once

#include "State.h"
#include "Button.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;
	string instructions="";
	string instructions2="";
	string instructions3="";
	string instructions4="";
	ofTrueTypeFont dibujotexto;
public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	
};
