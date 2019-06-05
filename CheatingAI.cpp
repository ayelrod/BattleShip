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

std::vector<BattleShip::Move> BattleShip::CheatingAI::makeVector(std::unique_ptr<Player>& otherPlayer) {
    std::vector<Move> possibleMoves;
    for(int i = 0; i < getBoard().getNumRows(); i++){
        for(int k = 0; k < getBoard().getNumCols(); k++){
            for(auto ship : shipHealths) {
                if (otherPlayer->getBoard().getFiringBoard()[i][k] == ship.first.getSymbol()) {
                    Move temp(i, k);
                    possibleMoves.push_back(temp);
                }
            }
        }
    }
    return possibleMoves;
}

BattleShip::Move BattleShip::CheatingAI::getPosition(std::unique_ptr<Player>& otherPlayer) {
    std::vector<Move> possibleMoves = makeVector(otherPlayer);
    int randInt = getRandInt(0, getBoard().getNumRows() - 1, randomNumberGenerator);
    return possibleMoves[randInt];
}
