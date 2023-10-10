//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);

}

void Burger::removeIngredient(Item *item) { //este function es para remover el ultimo infrediente que el jugador puso
    if (ingredients.size()>0){
        ingredients.pop_back();
    }
    
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.clear();
}

bool Burger::equals(Burger* b2){
    bool exist = false; //para saber si esta o existe    
     if (b2->ingredients.size() != this->ingredients.size()) {
        return false; 
    }
    for(int i=1;i<ingredients.size()-1;i++){
        if(b2->ingredients[i]->name == ingredients[i]->name) {
            exist = true;
        }
        else{
            return false;
        }  
    }
    return exist;
}

int Burger::BurgerPrice(vector<Item*> ingredients) const {
   
    int cheeses = 0;
    int lettuces = 0;
    int tomatoes = 0;
    int pattys = 0; 

    for (auto* ingredient : ingredients){
        if (ingredient->name == "cheese") {
            ++cheeses;
        } else if (ingredient->name == "lettuce") {
            ++lettuces;
        } else if (ingredient->name == "tomato") {
            ++tomatoes;
        } else if(ingredient->name == "patty") {
            ++pattys;
        }
    }
    int burgerPrice = (3 * cheeses) + (2 * lettuces) + (2 * tomatoes) + (4 * pattys) + 2;
    return burgerPrice;
}

vector<Item*> Burger::getIngredients() {
    return ingredients;
}