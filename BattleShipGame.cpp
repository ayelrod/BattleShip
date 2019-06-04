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
    do {
        takeTurn(players, currentTurn);
        changeTurn(currentTurn);
    }while(!gameOver());
    changeTurn(currentTurn);
    printWinner(currentTurn);

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
        auto player2 = std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships));
        this->players.push_back(player1);
        this->players.push_back(player2);
    }
    else{
        auto player1 = std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships));
        auto player2 = std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships));
        this->players.push_back(player1);
        this->players.push_back(player2);
    }
}

void BattleShip::BattleShipGame::takeTurn(std::vector<std::unique_ptr<Player>> players, int currentTurn) {
    std::unique_ptr<Player>& player = players[currentTurn], otherPlayer;
    if(currentTurn == 1){
        std::unique_ptr<Player>& otherPlayer = players[0];
    }
    else{
        std::unique_ptr<Player>& otherPlayer = players[1];
    }
    player->getBoard().displayFiring(player->getName());
    player->getBoard().displayPlacement(player->getName());
    Move move = getPosition(player);
    player->getBoard().makeMove(move, otherPlayer, players[currentTurn]->getName());

}

void BattleShip::BattleShipGame::changeTurn(int& currentTurn) {
    if(currentTurn == 0){
        currentTurn = 1;
    }
    else{
        currentTurn = 0;
    }
}

BattleShip::Move BattleShip::BattleShipGame::getPosition(std::unique_ptr<Player> &player) {
    return player->getPosition();
}

bool BattleShip::BattleShipGame::gameOver() {
    int numDestroyedShips = 0;
    for(auto& ship : players[0]->getShipHealths()){
        if(ship.second == 0){
            destroyedShip(ship.first);
            numDestroyedShips++;
        }
        if(numDestroyedShips == gameAttributes.getNumShips()){
            return true;
        }
    }
    numDestroyedShips = 0;
    for(auto& ship : players[1]->getShipHealths()){
        if(ship.second == 0){
            destroyedShip(ship.first);
            numDestroyedShips++;
        }
        if(numDestroyedShips == gameAttributes.getNumShips()){
            return true;
        }
    }
    return false;

}

void BattleShip::BattleShipGame::printWinner(int currentTurn) {
    std::cout << " 1 won the game!" << std::endl;
}

void BattleShip::BattleShipGame::destroyedShip(const Ship& ship) {
    std::unique_ptr<Player>& otherPlayer = players[1];
    if (currentTurn != 0){
        std::unique_ptr<Player>& otherPlayer = players[0];
    }

    if(ship.getDestroyed() == false){
        std::cout << players[currentTurn]->getName() << " destroyed " << otherPlayer->getName() << "'s " << ship.getSymbol() << "!";
    }

}
