#include "State.h"
#include "Button.h"

class LoseState : public State {
private:
	ofImage img1;
	Button *startButton; //recordar al final borrar lo que no uso
	string instructions="";
	string instructions2="";
	ofTrueTypeFont dibujotexto;
public:
	LoseState();
	void initItems();//cree esto para poder dar crop
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	ofImage gameOver;
};
