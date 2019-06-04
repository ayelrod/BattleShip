//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "BattleShipGame.h"

BattleShip::BattleShipGame::BattleShipGame(int numRows, int numCols, int numShips, std::vector<char>& shipChars,
                                           std::vector<int>& shipSizes, int gameType, int seed) : gameAttributes(GameAttributes(numRows, numCols, numShips, shipChars, shipSizes, gameType, seed))
                                           , currentTurn(0){

}

void BattleShip::BattleShipGame::playGame() {
    initializePlayers(gameAttributes);


}

void BattleShip::BattleShipGame::initializePlayers(GameAttributes& gameAttributes) {
    ShipPosition tempPosition;
    std::vector<Ship> ships;
    for(int i = 0; i < gameAttributes.getNumShips(); i++){
        ships.emplace_back(Ship(gameAttributes.getShipChars()[i], gameAttributes.getShipSizes()[i], tempPosition));
    }
    int gameType = gameAttributes.getGameType();
    if(gameType == 1){
        this->players.push_back(HumanPlayer())
    }
}
