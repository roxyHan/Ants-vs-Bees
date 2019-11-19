//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_THROWER_H
#define LAB5_THROWER_H


#include "Ant.h"

class Thrower : public Ant {

public:
    Thrower(int p);
    void action(Game* game);
};


#endif //LAB5_THROWER_H
