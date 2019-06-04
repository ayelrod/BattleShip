//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "BattleShipGame.h"

BattleShip::BattleShipGame::BattleShipGame(int numRows, int numCols, int numShips, std::vector<char>& shipChars,
                                           std::vector<int>& shipSizes, int gameType, int seed) : gameAttributes(GameAttributes(numRows, numCols, numShips, shipChars, shipSizes, gameType, seed))
                                           , currentTurn(0){

}

void BattleShip::BattleShipGame::playGame() {

}
