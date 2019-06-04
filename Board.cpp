//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "Board.h"

BattleShip::Board::Board(const BattleShip::GameAttributes& gameAttributes) : firingBoard(gameAttributes.getNumRows(), std::string(gameAttributes.getNumCols(), '*')),
    placementBoard(gameAttributes.getNumRows(), std::string(gameAttributes.getNumCols(), '*')){}

int BattleShip::Board::getNumRows() {
    return placementBoard.size();
}

int BattleShip::Board::getNumCols() {
    return placementBoard[0].size();
}
