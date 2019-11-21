//
// Created by Hanifa on 11/13/2019.
//

#include "Game.h"
#include <vector>
#include "Thrower.h"

Thrower::Thrower(int p) : Ant(p) {
    this->name = "Thrower";
    this->armor = 1;
    this->foodCost = 4;
}

void Thrower::action(Game *game) {
    int p = this->getLocation();
    std::vector<Insect*> square = game->getBoard(p);
    //bool find_a_bee = false;
    std::vector<Insect*>::iterator itr;
    for (itr = square.begin(); itr != square.end(); itr++) {
        if (!((*itr)->isInsectAnAnt())) {
            (*itr)->damage(1);
           // find_a_bee = true;
        }
    }
}