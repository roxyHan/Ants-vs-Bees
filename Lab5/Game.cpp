//
// Created by Hanifa on 11/13/2019.
//

#include <iostream>
#include "Game.h"
#include "Bee.h"

using namespace std;

// Big three and constructor
Game::Game() {
    this->num_bees = 0;
    this->winner = false;
    this->board[10];
    this->has_queen = false;
    Ant* antQueen = new Ant(0);
    antQueen->setQueen();
    addAnt(*antQueen);
    cout << "Board";
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
        Bee* twoB = new Bee(9);
        addBee(*twoB); // add it to the board

        // 2. The player can generate an ant and place it anywhere on the board.
        // Asks the user for the location of the ant and the type of ant
        if (this->p.getFoodBank() > 1) {
            Ant &oneAnt = p.generateAnt(this);
            if ((&oneAnt) != NULL) {
                addAnt(oneAnt);
            }
        }
        // Start of turn
        cout << "------------------------------------------------" << endl;
        cout << "Start of turn " << turn << endl;
        cout << "------------------------------------------------" << endl;
        displayBoard();
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
                    }
                }
            }
        }
        cout << "-------------------------------\n"
                "     After the ant attack:     \n"
                "-------------------------------" << endl;
        displayBoard();

        // 4. The bees either attack an ant (order of attack is left to right)
        //    which is blocking them or pass through to the next square on the
        //    board if they are not blocked by an ant.
        for (int i = 1; i < 10; i++) {
            std::vector<Insect*> square = this->getBoard(i);
            if (containsAnt(square) && containsBee(square)) {
                std::vector<Insect*> :: iterator itr;
                bool keep_attacking = true;
                for (itr = square.begin(); itr != square.end(); itr++) {
                    if (!(*itr)->isInsectAnAnt() && (*itr)->isAlive() && keep_attacking) {
                        Bee *one;
                        one = dynamic_cast<Bee *>(*itr);
                        one->action(this);
                        keep_attacking = false;
                    }
                }
            }
            else if (containsBee(square) && !containsAnt(square)){
                moveBeesT(i);
            }
            else{}
        }
        // End of turn
        cout << "------------------------------------------------" << endl;
        cout << " After the bee attack: End of turn " << turn << endl;
        cout << "------------------------------------------------" << endl;
        displayBoard();
        upBoard();

// 5. Check to see if the bees have reached the queen or if there are any
//    bees left in play, declare a winner and end the game if either
//    condition is true.
        if (num_bees <= 0) {
            winner = true;
            std::cout << "*****----------------------*****\n"
                         "        Yes!The ants won!      \n"
                         "*****----------------------*****"<< std::endl;
        } else if (reachQueen()) {
            winner = true;
            std::cout << "*****--------------------------*****\n"
                         "       You lost! The Bees won!      \n"
                         "*****--------------------------*****"<< std::endl;
        }
        turn++;
    } while (!winner);
}

// --------------------------------
//      Other functions
// --------------------------------
int Game::getNumBees() {
    return this->num_bees;
}

void Game::updateBeesCount(int n) {
    this->num_bees += n;
}

void Game::addAnt(Ant& anAnt) {
    // Previously checked that there was no conflict before adding
    int loc = (&anAnt)->getLocation();
    std::vector<Insect*> :: iterator itr;
    // Check that there is no ant at that location
    if (!containsAnt(this->board[loc])){
        if ((&anAnt)->isAlive()) {
            int loc = (&anAnt)->getLocation();
            board[loc].push_back(&anAnt);
        }
    }
    else if ((&anAnt)->getName() == "Bodyguard") {
        int only_guard = 0;
        for (itr = this->board[loc].begin(); itr != this->board[loc].end(); itr++) {
            if ((*itr)->isInsectAnAnt() && (*itr)->getName() == "Bodyguard") {
                only_guard++;
            }
        }
        if (only_guard == 0) {
            board[loc].push_back(&anAnt);
        }
    }
    else if ((&anAnt)->getName() != "Bodyguard" && containsAnt(board[loc])) {
        int only_guard = 0;
        for (itr = this->board[loc].begin(); itr != this->board[loc].end(); itr++) {
            if ((*itr)->isInsectAnAnt() && (*itr)->getName() == "Bodyguard") {
                only_guard++;
            }
        }
        if (only_guard == 1) {
            board[loc].push_back(&anAnt);
        }
    }
    else{
        int reimbursment = anAnt.getFoodCost() * (-1);
        this->p.withdrawCost(reimbursment);
        cout << "Impossible to place a " << (&anAnt)->getName() << " on this square" << endl;
    }
}

/**
 *
 * @param aBee
 * @param location
 */
void Game::addBee(Bee& aBee) {
    if ((&aBee)->isAlive()) {
        int loc = (&aBee)->getLocation();
        board[loc].push_back(&aBee);
    }
    updateBeesCount(1);
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

void Game::moveBeesT(int u) {

    std::vector<Insect*> :: iterator itr;
    for (itr = this->board[u].begin(); itr != this->board[u].end(); itr++) {
        if (!((*itr)->isInsectAnAnt()) ) {
            Bee * bee;
            bee = dynamic_cast<Bee*>(*itr);
            bee->move();
            addBee(*bee);
            this->board[u].erase(itr--);
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
    //std::cout << "Board";
    for (int i = 0; i < 10; i++) {
        vector<Insect*> sq = this->getBoard(i);
        cout << "\nSquare " << i << ": ";
        std::vector<Insect*> :: iterator itr;
        for (itr = sq.begin(); itr != sq.end(); itr++) {
            cout << (*itr)->getName() << "(" << (*itr)->getArmor() << ")\t" << endl;
        }
    }
    cout << "\n" << endl;
}

bool Game::reachQueen() {
    vector<Insect*> sq = this->board[0];
    std::vector<Insect*> :: iterator itr;
    for (itr = sq.begin(); itr != sq.end(); itr++) {
        if (!((*itr)->isInsectAnAnt())) {
            return true;
        }
    }
    return false;
}

void Game::upBoard() {
    for (int i = 0; i < 10; i++) {
        std::vector<Insect*> :: iterator itr;
        for (itr = this->board[i].begin(); itr != this->board[i].end(); itr++) {
            if (!((*itr)->isAlive())) {
                this->board[i].erase(itr--);
            }
        }
    }
}