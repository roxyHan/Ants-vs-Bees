//
// Created by Hanifa on 11/13/2019.
//

#include "Harvester.h"
#include "Game.h"

Harvester::Harvester(int p) : Ant(p) {
    this->name = "Harvester";
    this->armor = 1;
    this->foodCost = 2;
}

/**
 *
 * @return
 */
void Harvester::action(Game *aBoard) {
    if (this->status) {
        Player* player;
        player = aBoard->getPlayer();
        player->addToBank();
        int y = 0;
        y = player->getFoodBank();
        int u = 0;
        u = aBoard->getPlayer()->getFoodBank();
        int r = 0;
    }
}