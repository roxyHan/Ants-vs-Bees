//
// Created by Hanifa on 11/10/2019.
//

#include "Insect.h"

/**
 * Constructor for the Insect Object
 * @param armor
 * @param place
 */
Insect::Insect(int place) {
    this->place = place;
    this->status = true;
}


/**
 *
 * @param newOne
 */
Insect::Insect(Insect const &newOne){
}

Insect& Insect::operator=(const Insect &oneInsect) {

}

Insect::~Insect() {

}

/**
 *
 * @return
 */
int Insect::getArmor() {
    return this->armor;
}

/**
 *
 * @return
 */
bool Insect::isAlive() {
   /** if (this->name == "Fire") {
        if (this->armor < 0 && this->name != "Queen"){
            this->status = false;
        }
    }*/
    //else if (this->name != "Fire") {
        if (this->armor <= 0 && this->name != "Queen"){
            this->status = false;
        }
    //}
    return this->status;
}

int Insect::getLocation() {
    return this->place;
}

void Insect::damage(int num) {
    if (num == 1) {
        this->armor--;
    }
    else{
        this->armor = 0;
    }
}
/**
 *
 * @return
 */
std::string Insect::getName() {
    return this->name;
}

/**
 *
 */
void Insect::kill() {
    if (armor <= 0) {
        status = false;
        delete this;
    }
}

bool Insect::isInsectAnAnt() {
    return this->is_ant;
}

void action(Game *newBoard) {}