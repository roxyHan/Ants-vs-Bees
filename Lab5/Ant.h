//
// Created by Hanifa on 11/10/2019.
//

#ifndef LAB5_ANT_H
#define LAB5_ANT_H


#include "Insect.h"

class Game;

class Ant: public Insect {

protected:
    int foodCost;

public:
    Ant(int place);
    Ant(const Ant &newOne);
    //Ant& operator=(const Ant& game);
    void copy(const Ant& ant);
    ~Ant();
    void setQueen();
    int getFoodCost();
    void action(Game* game);

};


#endif //LAB5_ANT_H
