//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_NINJA_H
#define LAB5_NINJA_H


#include "Ant.h"

class Ninja : public Ant {

public:
    Ninja(int p);
    void action(Game * game);
};


#endif //LAB5_NINJA_H
