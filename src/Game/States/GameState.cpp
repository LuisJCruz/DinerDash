#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if(restaurant->entityManager->contadorPersonas==10){
		restaurant->setLeavingPersons(0);
		setNextState("Lose");
		setFinished(true);
	}
	if(restaurant->getMoney()>=100){
		setNextState("Win");
		setFinished(true);
		restaurant->setMoney(0);
	}

	//aqui pongo el code de si se me van los clientes se pasa al otro state
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}