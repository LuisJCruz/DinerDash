//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;

  public:
    vector<Item *> ingredients;
    map<string, int> middleIngredients = {
      {"patty",0},
      {"tomato",0},
      {"lettuce",0},
      {"cheese",0}};
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void removeIngredient(Item *item);
    void render();
    void clear();
    int BurgerPrice(vector<Item*> ingredients) const;
    void setY(int y) {
        this->y = y;
    }
    bool equals(Burger* b2);//estoy creando la funcion que compara los 2 hamburguers
    vector<Item*> getIngredients();
};
