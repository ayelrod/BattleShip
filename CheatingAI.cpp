//
// Created by Lucas Rodriguez on 2019-06-04.
//

#include "CheatingAI.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships)
        : ships(ships), board(gameAttributes){
    this->initializeName();
    for(int i = 0; i < ships.size(); i++){
        shipHealths[ships[i]] = gameAttributes.getShipSizes()[i];
    }
    placeShips();
}

void BattleShip::CheatingAI::initializeName() {
    AiPlayer::initializeName();
}

void BattleShip::CheatingAI::setName(std::string name) {
    this->name = name;
}

void BattleShip::CheatingAI::placeShips() {
    AiPlayer::placeShips();
}

std::map<BattleShip::Ship, int> BattleShip::CheatingAI::getShipHealths() {
    return shipHealths;
}
