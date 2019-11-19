//
// Created by Hanifa on 11/13/2019.
//

#include <iostream>
#include "Game.h"
#include "Bee.h"

using namespace std;

// Big three and constructor
Game::Game() {
    this->winner = false;
    this->board[10];
    this->has_queen = false;
    Ant* antQueen = new Ant(0);
    antQueen->setQueen();
    addAnt(*antQueen);
    displayBoard();

}

Game::Game(const Game &game) {
    copy(game);
}

Game& Game::operator=(const Game &game) {
    for (int i = 0; i < 10; i++) {
        this->board[i].clear();
    }
    copy(game);
}

void Game::copy(const Game& g) {
    this->p = g.p;
    //this->foodBank = g.foodBank;
    for (int i = 0; i < 10; i++) {
        this->board[i] = g.board[i];
    }
    this->num_bees = g.num_bees;
    this->has_queen = g.has_queen;
}


Game::~Game() {
    for (int i = 0; i < 10; i++) {
        board[i].clear();
    }
}

// Methods

void Game::run() {
    int turn = 1;

    do {
        // 1. A Bee is generated on the right side of the board
        int rt = 0;
        Bee *aBee = new Bee(9);
        addBee(*aBee); // add it to the board

        // 2. The player can generate an ant and place it anywhere on the board.
        // Asks the user for the location of the ant and the type of ant
        Ant& oneAnt = p.generateAnt(this);
        addAnt(oneAnt);

        // 3. The ants attack the bees. (Order of ant attacks occur left to right).
        for (int i = 1; i < 10; ++i) {
            std::vector<Insect*> square = this->getBoard(i);
            std::vector<Insect*>::iterator itr;
            if (containsAnt(square)) {
                for (itr = square.begin(); itr != square.end(); itr++) {
                    if ((*itr)->isInsectAnAnt()) {
                        Ant* one;
                        one = dynamic_cast<Ant *>(*itr);
                        one->action(this);
                        updateS(*itr);
                    }
                }
            }
        }

        // 4. The bees either attack an ant (order of attack is left to right)
        //    which is blocking them or pass through to the next square on the
        //    board if they are not blocked by an ant.
        for (int i = 1; i < 10; i++) {
            std::vector<Insect*> square = this->getBoard(i);
            if (containsAnt(square) && containsBee(square)) {
                std::vector<Insect*> :: iterator itr;
                for (itr = square.begin(); itr != square.end(); itr++) {
                    if ((*itr)->isInsectAnAnt()) {
                        Ant* one;
                        one = dynamic_cast<Ant*>(*itr);
                        (*itr)->damage(1);
                    }
                    updateS(*itr);
                }
            }
            else if (containsBee(square) && !containsAnt(square)){
                int x = 0;
                moveBees(&square);
                int c = 0;
            }
            else{}
        }

// 5. Check to see if the bees have reached the queen or if there are any
//    bees left in play, declare a winner and end the game if either
//    condition is true.
        if (num_bees <= 0) {
            winner = true;
            std::cout << "The ants won!" << std::endl;
        } else if (has_queen) {
            winner = true;
            std::cout << "The bees won!" << std::endl;}
        turn++;
    } while (!winner);
}

// --------------------------------
//      Other functions
// --------------------------------

/**
 *
 * @param anAnt
 * @param location
 * @return
 */
void Game::addAnt(Ant& anAnt) {
    // Previously checked that there was no conflict before adding
    int loc = (&anAnt)->getLocation();
    // Check that there is no ant at that location
    if (!containsAnt(this->board[loc])){
        if ((&anAnt)->isAlive()) {
            int loc = (&anAnt)->getLocation();
            board[loc].push_back(&anAnt);
        }
    }
}

bool Game::containsAnt(std::vector<Insect *> aI) {
    std::vector<Insect*> :: iterator itr;
    for (itr = aI.begin(); itr != aI.end(); itr++) {
        if ((*itr)->isInsectAnAnt() ) {
            return true;
        }
    }
    return false;
}

bool Game::containsBee(std::vector<Insect *> aI) {
    std::vector<Insect*> :: iterator itr;
    for (itr = aI.begin(); itr != aI.end(); itr++) {
        if (!((*itr)->isInsectAnAnt()) ) {
            return true;
        }
    }
    return false;
}

/**
 *
 * @param aBee
 * @param location
 */
void Game::addBee(Bee& aBee) {
    int loc = aBee.getLocation();
    if ((&aBee)->isAlive()) {
        int loc = (&aBee)->getLocation();
        board[loc].push_back(&aBee);
    }
    this->num_bees++;
}

void Game::moveBees(std::vector<Insect *> *sq) {
    std::vector<Insect*> :: iterator itr;
    for (itr = sq->begin(); itr != sq->end(); itr++) {
        if (!((*itr)->isInsectAnAnt()) ) {
            Bee * bee;
            bee = dynamic_cast<Bee*>(*itr);
            bee->move();
            addBee(*bee);
            //sq->erase(itr);
            //--itr;
        }
    }
}

std::vector<Insect*> Game::getBoard(int iplace) {
    return this->board[iplace];
}

Player* Game::getPlayer() {
    return &(this->p);
}

void Game::displayBoard() {
    std::cout << "Board\n" << std::endl;
    for (int i = 0; i < 10; i++) {
        vector<Insect*> sq = this->getBoard(i);
        cout << "\nSquare " << i << ": ";
        std::vector<Insect*> :: iterator itr;
        for (itr = sq.begin(); itr != sq.end(); itr++) {
            cout << (*itr)->getName() << "\t" << endl;
        }
    }
    cout << "\n" << endl;
}