//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "BattleShipGame.h"
#include "AiPlayer.h"

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
    //create vector of ships
    for(int i = 0; i < gameAttributes.getNumShips(); i++){
        ships.emplace_back(Ship(gameAttributes.getShipChars()[i], gameAttributes.getShipSizes()[i], tempPosition));
    }

    //get game type
    int gameType = gameAttributes.getGameType();

    //if human vs human
    if(gameType == 1){
        auto player1 = std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1));
        auto player2 = std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 2));
        this->players.push_back(player1);
        this->players.push_back(player2);
    }
    else if(gameType == 2){
        auto player1 = std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1));
        Player* player2 = new AiPlayer();
    }
}
