//
// Created by Hanifa on 11/13/2019.
//

#include "Wall.h"

Wall::Wall(int place) : Ant(place) {
    this->name = "Wall";
    this->armor = 4;
    this->foodCost = 4;
}

void Wall::action(Game *game) {

}