//
// Created by Lucas Rodriguez on 2019-06-04.
//

#include "HuntDestroyAI.h"

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships)
    :  board(gameAttributes) ,ships(ships){
    this->initializeName();
    for(int i = 0; i < ships.size(); i++){
        shipHealths[ships[i].getSymbol()] = gameAttributes.getShipSizes()[i];
    }
    placeShips();
}

void BattleShip::HuntDestroyAI::initializeName() {
    AiPlayer::initializeName();
}

void BattleShip::HuntDestroyAI::setName(std::string name) {
    this->name = name;
}

std::vector<BattleShip::Move> BattleShip::HuntDestroyAI::makeVector() {
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

std::map<char, int>& BattleShip::HuntDestroyAI::getShipHealths() {
    return shipHealths;
}

BattleShip::Move BattleShip::HuntDestroyAI::getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) {

    return AiPlayer::getPosition(player, otherPlayer);
}

BattleShip::Board &BattleShip::HuntDestroyAI::getBoard() {
    return board;
}

BattleShip::HuntDestroyAI::~HuntDestroyAI() {

}

void BattleShip::HuntDestroyAI::placeShips() {
    std::vector<char> orientation_choice{'h', 'v'};
    const int numRows = getBoard().getNumRows();
    const int numCols = getBoard().getNumCols();

    ShipPosition placement;
    for(const auto& ship : ships) {
        do {
            char orientation = *chooseRandom(orientation_choice, randomNumberGenerator);
            if (orientation == 'h') {
                placement.rowStart = getRandInt(0, numRows - 1, randomNumberGenerator);
                placement.colStart = getRandInt(0, numCols - ship.getSize(), randomNumberGenerator);
                placement.rowEnd = placement.rowStart;
                placement.colEnd = placement.colStart + ship.getSize() - 1;
            } else {
                placement.rowStart = getRandInt(0, numRows - ship.getSize(), randomNumberGenerator);
                placement.colStart = getRandInt(0, numCols - 1, randomNumberGenerator);
                placement.rowEnd = placement.rowStart + ship.getSize() - 1;
                placement.colEnd = placement.colStart;
            }
        }while(!getBoard().canPlaceShipAt(placement));
        getBoard().AddShip(ship, placement);
        getBoard().displayPlacement(name);
        //view.showPlacementBoard(*this);
    }
}
