//
// Created by Lucas Rodriguez on 2019-06-04.
//

#include "HuntDestroyAI.h"

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships)
    :  ships(ships), board(gameAttributes) {
    this->initializeName();
    for(int i = 0; i < ships.size(); i++){
        shipHealths[ships[i]] = gameAttributes.getShipSizes()[i];
    }
    placeShips();
}

void BattleShip::HuntDestroyAI::initializeName() {
    AiPlayer::initializeName();
}

void BattleShip::HuntDestroyAI::setName(std::string name) {
    this->name = name;
}


