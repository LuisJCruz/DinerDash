#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    ofSetColor (255,255,255); // puse este color aqui para que no cambie el color de los hamnburguers
    burger->render();
    double percent=patience/2000.0; // variable para que se vaya actualizando el color
    ofColor redColor= ofColor(255,255*percent,255*percent); //variable del nuevo color
    ofSetColor(redColor); 
    sprite.draw(x, y, width, height);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    if(this->burger->equals(burger)){
        isLeaving = true;
        burger->clear();
        return burger->BurgerPrice(this->burger->getIngredients());
    }
    else if(nextClient != nullptr){
        return nextClient->serve(burger);
    }
    else {
        burger->clear();
        isLeaving = false;
        return 0;
    }
}

int Client::getPatience(){
    return patience;
}

