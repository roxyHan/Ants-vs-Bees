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

Bee::Bee(const Bee &another) : Insect(another) {
    copy(another);
}


void Bee::copy(const Bee &b) {

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
    bool guard = false;
    for (itr = square.begin(); itr != square.end(); itr++) {
        if ((*itr)->isInsectAnAnt() && (*itr)->getName() == "Bodyguard") {
            (*itr)->damage(1);
            guard = true;
            break;
        }
    }
    if (!guard) {
        for (itr = square.begin(); itr != square.end(); itr++) {
            if ((*itr)->isInsectAnAnt()) {
                (*itr)->damage(1);
            }
            if (!(*itr)->isAlive() && (*itr)->getName() == "Fire") {
                (*itr)->action(game);
            }
        }
    }
}

