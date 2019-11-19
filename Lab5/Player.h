//
// Created by Hanifa on 11/17/2019.
//
#ifndef LAB5_PLAYER_H
#define LAB5_PLAYER_H

#include "Ant.h"

class Player {

protected:
    int foodBank;


public:
    Player();
    ~Player();

    int getFoodBank();
    bool withdrawCost(int cost);
    void addToBank();
    Ant& generateAnt(Game * g);
    int displayList();
    int selectLocation(Game * game);

};


#endif //LAB5_PLAYER_H
