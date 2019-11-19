//
// Created by Hanifa on 11/10/2019.
//

#include "Bee.h"
#include "Game.h"

Bee::Bee(int place) : Insect(place){
    this->armor = 3;
    this->status = true;
    this->is_ant = false;
    this->name = "bee";
}

Bee::~Bee() {

}


void Bee::move() {
    this->place--;
}

void Bee::action(Game *game) {
    int p = this->getLocation();
    std::vector<Insect*> square = game->getBoard(p);
    std::vector<Insect*>::iterator itr;
    for (itr = square.begin(); itr != square.end(); itr++) {
        if ((*itr)->isInsectAnAnt()) {
            (*itr)->damage(1);
        }
    }
}

