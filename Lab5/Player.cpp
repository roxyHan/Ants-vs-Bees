//
// Created by Hanifa on 11/17/2019.
//

#include <iostream>
#include <vector>
#include "Player.h"
#include "Harvester.h"
#include "Thrower.h"
#include "Fire.h"
#include "Long_Thrower.h"
#include "Short_Thrower.h"
#include "Wall.h"
#include "Ninja.h"
#include "Bodyguard.h"
#include "Game.h"

using namespace std;


Player::Player() {
    this->foodBank = 50;
}

Player::~Player() {

}

int Player::getFoodBank() {
    return this->foodBank;
}

bool Player::withdrawCost(int cost) {
    if (foodBank >= cost) {
        this->foodBank -= cost;
        return true;
    }
    else{
        cout << "Insufficient food balance" << endl;
        return false;
    }
}

void Player::addToBank() {
    this->foodBank++;
}

Ant& Player::generateAnt(Game * game) {
    Ant *choix; // Creates a new ant
    // choiceAnt and choiceLocation
    bool purchasable = false;
    while (!purchasable) {
        int typeN = displayList();
        int caseNum = selectLocation(game);
        // User picks one ant and choose where to put it on the board

        switch (typeN) {
            case 1: {
                Harvester* harvester = new Harvester(caseNum);
                choix = harvester;
                break;
            }
            case 2: {
                Thrower *thrower = new Thrower(caseNum);
                choix = thrower;
                break;
            }
            case 3: {
                Fire *fire = new Fire(caseNum);
                choix = fire;
                break;
            }
            case 4: {
                Long_Thrower* longThrower = new Long_Thrower(caseNum);
                choix = longThrower;
                break;
            }
            case 5: {
                Short_Thrower* shortThrower = new Short_Thrower(caseNum);
                choix = shortThrower;
                break;
            }
            case 6: {
                Wall* wall = new Wall(caseNum);
                choix = wall;
                break;
            }
            case 7: {
                Ninja* ninja = new Ninja(caseNum);
                choix = ninja;
                break;
            }
            case 8: {
                Bodyguard* bodyguard = new Bodyguard(caseNum);
                choix = bodyguard;
                break;
            }
        }
        purchasable = withdrawCost(choix->getFoodCost());
    }
    return *choix;
}

int Player::displayList() {
    string type;
    // Display food bank and ants list
    cout << "------------------------------------------------\n" <<
         "Current food bank: " << this->getFoodBank() << endl;

    // Ants List
    cout << "ID         ||   (1) \t\t (2) \t\t (3) \t\t (4) \t\t (5) \t\t (6) \t (7)\t\t(8)\n" <<
         "Type:      || Harvester\t  Thrower\t\tFire\tLongThrower\t "
         "ShortThrower\tWall\tNinja\tBodyguard" << endl;
    cout << "Food cost: ||  \t2\t\t \t4 \t\t\t 4 \t\t\t 3 \t\t\t 3 \t\t\t 4 \t\t 6 \t\t\t 4 \n" << endl;
    cout << "Buy an ant with your current food balance. Enter the ID number from 1 to 8: " << endl;
    getline(cin, type);
    return stoi(type);
}



int Player::selectLocation(Game * game) {
    game->displayBoard();
    string location;
    std::cout << "Please enter the location you wish to put your ant on: " << std::endl;
    std::getline(std::cin, location);
    return stoi(location);
}


