//
// Created by Hanifa on 11/13/2019.
//

#include <vector>
#include "Short_Thrower.h"
#include "Game.h"

Short_Thrower::Short_Thrower(int place) : Ant(place) {
    this->name = "Short_T";
    this->armor = 1;
    this->foodCost = 3;
}

void Short_Thrower::action(Game *game) {
    int p = this->getLocation();
    int flag = false;
    if (p + 2 <= 9) {
        std::vector<Insect*> square = game->getBoard(p + 2);
        std::vector<Insect*>::iterator itr;
        for (itr = square.begin(); itr != square.end(); itr++) {
            if (!(*itr)->isInsectAnAnt()) {
                (*itr)->damage(1);
            }
        }
    }
    if (p + 1 <= 9) {
        std::vector<Insect*> square = game->getBoard(p + 1);
        std::vector<Insect*>::iterator itr;
        for (itr = square.begin(); itr != square.end(); itr++) {
            if (!(*itr)->isInsectAnAnt()) {
                (*itr)->damage(1);
            }
        }
    }
}