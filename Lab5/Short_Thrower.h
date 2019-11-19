//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_SHORT_THROWER_H
#define LAB5_SHORT_THROWER_H


#include "Ant.h"

class Short_Thrower : public Ant {

public:
    Short_Thrower(int place);
    void action(Game * game);

};


#endif //LAB5_SHORT_THROWER_H
