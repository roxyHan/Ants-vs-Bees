//
// Created by Hanifa on 11/10/2019.
//

#ifndef LAB5_INSECT_H
#define LAB5_INSECT_H

#include <string>

class Game;

class Insect {

protected:
    int armor;
    int place;
    bool status;
    bool is_ant;
    std::string name;

public:
    // Big 3
    Insect(int p);
    Insect(const Insect& newOne);
    Insect& operator=(const Insect& oneInsect);
    ~Insect();

    // methods
    int getArmor();
    bool isAlive();
    int getLocation();
    void damage(int n);
    void kill();

    virtual void action(Game* newBoard) {};
    bool isInsectAnAnt();
    std::string getName();

};


#endif //LAB5_INSECT_H
