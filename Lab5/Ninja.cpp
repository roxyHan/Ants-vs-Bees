//
// Created by Hanifa on 11/13/2019.
//

#include <vector>
#include "Ninja.h"
#include "Game.h"

Ninja::Ninja(int p) : Ant(p) {
    this->name = "Ninja";
    this->armor = 1;
    this->foodCost = 6;
}

void Ninja::action(Game *game) {
    int p = this->getLocation();
    std::vector<Insect*> square = game->getBoard(p);
    std::vector<Insect*>::iterator itr;
    for (itr = square.begin(); itr != square.end(); itr++) {
        if (!(*itr)->isInsectAnAnt()) {
            (*itr)->damage(1);
        }
    }
}