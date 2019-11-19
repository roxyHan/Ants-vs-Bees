//
// Created by Hanifa on 11/13/2019.
//

#include <vector>
#include "Game.h"
#include "Long_Thrower.h"

Long_Thrower::Long_Thrower(int p) : Ant(p) {
    this->name = "Long_T";
    this->armor = 1;
    this->foodCost = 3;
}

void Long_Thrower::action(Game *game) {
    int p = this->getLocation();
    if (p + 4 <= 9) {
        std::vector<Insect*> square = game->getBoard(p + 4);
        std::vector<Insect*>::iterator itr;
        for (itr = square.begin(); itr != square.end(); itr++) {
            if (!(*itr)->isInsectAnAnt()) {
                (*itr)->damage(1);
            }
        }
    }
}