//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_LONG_THROWER_H
#define LAB5_LONG_THROWER_H


#include "Ant.h"

class Long_Thrower: public Ant {

public:
    Long_Thrower(int p);
    void action(Game* game);
};


#endif //LAB5_LONG_THROWER_H
