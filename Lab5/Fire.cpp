//
// Created by Hanifa on 11/13/2019.
//

#include <vector>
#include "Game.h"
#include "Fire.h"

Fire::Fire(int place) : Ant(place) {
    this->name = "Fire";
    this->armor = 1;
    this->foodCost = 4;
}

void Fire::action(Game *game) {
    int p = this->getLocation();
    std::vector<Insect*> square = game->getBoard(p);
    std::vector<Insect*>::iterator itr;
    if (this->getArmor() <= 0) {
        for (itr = square.begin(); itr != square.end(); itr++) {
            if (!((*itr)->isInsectAnAnt())) {
                (*itr)->damage(0);
                square.erase(itr--);
                game->updateBeesCount(-1);
            }
        }
    }
}

