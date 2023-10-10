//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant {
    private:
        Player* player;
        int ticks=0;
        std::vector<ofImage> people;

    public:
        int money = 0;
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        ofImage table, mesa, silla; //puse aqui la variable tipo ofImage
        ofImage flores, planta;
        int insCounter = 0;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        EntityManager* entityManager;
        int getMoney(){
            return money;
        }
        void setMoney(int resetMoney){
            money=resetMoney;
        }
        void setLeavingPersons(int resetPersons){
            entityManager->contadorPersonas=resetPersons;
        }
        //cree los 2 setters para que se ponga siempre en 0 el dinero o personas que se van
        //porque si no hago eso sigo perdiendo o sigo ganando por siempre
        
};
