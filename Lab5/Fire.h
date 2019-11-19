//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_FIRE_H
#define LAB5_FIRE_H


#include "Ant.h"

class Fire : public  Ant {

public:
        Fire(int place);
        void action(Game * game);
};


#endif //LAB5_FIRE_H
