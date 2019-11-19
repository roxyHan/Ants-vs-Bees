//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_HARVESTER_H
#define LAB5_HARVESTER_H


#include "Ant.h"

class Harvester : public Ant {

public:
    Harvester(int p);
    void action(Game *aBoard);
};


#endif //LAB5_HARVESTER_H
