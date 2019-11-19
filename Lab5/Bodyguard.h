//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_BODYGUARD_H
#define LAB5_BODYGUARD_H


#include <string>
#include "Ant.h"

class Bodyguard : public Ant {
public:
    Bodyguard(int place);
    void action(Game * game);
};


#endif //LAB5_BODYGUARD_H
