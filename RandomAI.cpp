//
// Created by Lucas Rodriguez on 2019-06-04.
//

#include "RandomAI.h"

BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships)
        :  ships(ships), board(gameAttributes){
    this->initializeName();
    for(int i = 0; i < ships.size(); i++){
        shipHealths[ships[i]] = gameAttributes.getShipSizes()[i];
    }
    placeShips();
}

void BattleShip::RandomAI::initializeName() {
    AiPlayer::initializeName();
}

void BattleShip::RandomAI::setName(std::string name) {
    this->name = name;
}

std::map<BattleShip::Ship, int> BattleShip::RandomAI::getShipHealths() {
    return shipHealths;
}

