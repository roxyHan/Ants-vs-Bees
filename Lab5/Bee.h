//
// Created by Hanifa on 11/10/2019.
//

#ifndef LAB5_BEE_H
#define LAB5_BEE_H


#include "Insect.h"
//#include "Ant.h"

//class Ant;
class Game;

class Bee : public Insect{

public:
    Bee(int place);
    Bee(const Bee& another);
    //Bee& operator=(const Bee& b);
    void copy(const Bee& bee);
    ~Bee();
    // methods
    void action(Game* game);
    void move();
};


#endif //LAB5_BEE_H
