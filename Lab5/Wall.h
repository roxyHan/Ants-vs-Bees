//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_WALL_H
#define LAB5_WALL_H


#include "Ant.h"

class Wall : public Ant {

public:
    Wall(int place);
    void action(Game* game);
};


#endif //LAB5_WALL_H
