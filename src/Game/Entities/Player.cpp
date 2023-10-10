#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
    chefAnim->tick();
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                burger->addIngredient(item);
            }
        }
    }
    if (key == 'u'){ // este es el key que llama la funcion de remover el ultimo ingrediente
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                burger->removeIngredient(item);
            }
        }		
	}
    if (key == OF_KEY_LEFT){
        speed = 10;
        facing = "left";
        x-=speed;
        if(x <= 0){
            x=0;
        }
        
    }
    if (key == OF_KEY_RIGHT){
        speed = 10;
        facing = "right";
        x+=speed;
        if(x + width >= ofGetWidth()){
            x=ofGetWidth()-60;
        }
    }
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }