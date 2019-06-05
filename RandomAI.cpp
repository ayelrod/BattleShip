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

BattleShip::Move BattleShip::RandomAI::getPosition(std::unique_ptr<Player>& otherPlayer) {
    std::vector<Move> possibleMoves = makeVector();
    int randInt = getRandInt(0, getBoard().getNumRows() - 1, randomNumberGenerator);
    return possibleMoves[randInt];
}

std::vector<BattleShip::Move> BattleShip::RandomAI::makeVector() {
    std::vector<Move> possibleMoves;
    for(int i = 0; i < getBoard().getNumRows(); i++){
        for(int k = 0; k < getBoard().getNumCols(); k++){
            if(getBoard().getFiringBoard()[i][k] == '*'){
                Move temp(i, k);
                possibleMoves.push_back(temp);
            }
        }
    }
    return possibleMoves;
}

