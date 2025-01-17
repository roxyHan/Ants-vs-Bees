//
// Created by Hanifa on 11/13/2019.
//

#ifndef LAB5_GAME_H
#define LAB5_GAME_H


#include <vector>
#include "Insect.h"
#include "Bee.h"
#include "Ant.h"
#include "Player.h"

class Insect;
class Bee;
class Ant;

class Game {

protected:
    Player p;
    int num_bees;
    bool has_queen;
    bool winner;
    std::vector<Insect*> board[10];


public:
    Game();
    Game(const Game& game);
    Game& operator=(const Game& game);
    void copy(const Game& game);
    ~Game();

    // methods
    void run();
    int getNumBees();
    void updateBeesCount(int n);
    void addAnt(Ant& a);
    void addBee(Bee& b);
    Player *getPlayer();
    template <class T>
    void updateS( T& a) {
        if (!(*a).isAlive()) {
            int loc = (*a).getLocation();
            (*a).kill();
        }
        else {
        }
    };
    void upBoard();
    bool containsAnt(std::vector<Insect*> aI);
    bool containsBee(std::vector<Insect*> bees);
    void moveBeesT(int u);
    std::vector<Insect*> getBoard(int i);
    void displayBoard();
    bool reachQueen();

};


#endif //LAB5_GAME_H
