//
// Created by Hanifa on 11/13/2019.
//

#include "Bodyguard.h"


Bodyguard::Bodyguard(int place): Ant(place) {
    this->name = "Bodyguard";
    this->armor = 2;
    this->foodCost = 4;
}

void Bodyguard::action(Game *game) {

}