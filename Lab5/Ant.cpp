//
// Created by Hanifa on 11/10/2019.
//

#include "Ant.h"

/**
 *
 * @param place
 */
Ant::Ant(int place) : Insect(place){
    this->place = place;
    this->is_ant = true;
}

Ant::Ant(const Ant &newOne) : Insect(newOne) {
    copy(newOne);
}


void Ant::copy(const Ant &insect) {
}

Ant::~Ant() {

}



/**
 *
 * @return
 */
int Ant::getFoodCost() {
    return this->foodCost;
}


void Ant::action(Game *game) {

}

void Ant::setQueen() {
    this->name = "Queen";
}
