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

void BattleShip::Board::AddShip(const BattleShip::Ship &ship, BattleShip::ShipPosition placement) {
    for(int i = placement.rowStart ; i <= placement.rowEnd; i++){
        for(int k = placement.colStart; k <= placement.colEnd; k++){
            placementBoard[i][k] = ship.getSymbol();
        }
    }
}

void BattleShip::Board::displayFiring(std::string name) {
    std::cout << name << "'s Firing Board" << std::endl;
    //print column headers
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = getNumRows() - 1;
    for (const auto& row : placementBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex--;
        std::cout << std::endl;
    }
}

void BattleShip::Board::displayPlacement(std::string name) {
    std::cout << name << "'s Placement Board" << std::endl;
    //print column headers
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = getNumRows() - 1;
    for (const auto& row : placementBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex--;
        std::cout << std::endl;
    }
}

void BattleShip::Board::makeMove(BattleShip::Move move, std::unique_ptr<Player>& otherPlayer, std::string name) {
    if(otherPlayer->getBoard().getPlacementBoard()[move.row][move.col] == '*'){
        this->firingBoard[move.row][move.col] = '0';
        otherPlayer->getBoard().firingBoard[move.row][move.col] = '0';
        std::cout << "You missed." << std::endl;
    }
    else{
        char shipChar = otherPlayer->getBoard().getPlacementBoard()[move.row][move.col];
        this->firingBoard[move.row][move.col] = 'X';
        otherPlayer->getBoard().firingBoard[move.row][move.col] = 'X';
        std::cout << name << " hit " << otherPlayer->getName() << "'s " << shipChar << "!";
    }
}

