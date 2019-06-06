//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "BattleShipGame.h"
#include "AiPlayer.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::BattleShipGame::BattleShipGame(int numRows, int numCols, int numShips, std::vector<char>& shipChars,
                                           std::vector<int>& shipSizes, int gameType, int seed) : currentTurn(0),
                                           gameAttributes(GameAttributes(numRows, numCols, numShips, shipChars, shipSizes, gameType, seed)){

}

void BattleShip::BattleShipGame::playGame() {
    BattleShip::AiPlayer::seed_random_number_generator(gameAttributes.getSeed());
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

    /////CALLL THE CORRECT CONSTRUCTOR HERE INSTEAD
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //if human vs human
    if(gameType == 1){
//        auto player1 = std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1));
//        auto player2 = std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 2));
        this->players.push_back(std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1)));
        this->players.push_back(std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 2)));
    }
    else if(gameType == 2){
//        auto player1 = std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1));
//        auto player2 = std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships));
        this->players.push_back(std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1)));
        int aiType = 0;
        do{
            std::cout << "What AI do you want" << std::endl;
            std::cout << "1. Cheating AI" << std::endl;
            std::cout << "2. Random AI" << std::endl;
            std::cout << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> aiType;
        } while(aiType != 1 && aiType != 2 && aiType != 3);
        if(aiType == 1) {
            this->players.push_back(std::unique_ptr<Player>(new CheatingAI(gameAttributes, ships)));
        }
        else if(aiType == 2){
            this->players.push_back(std::unique_ptr<Player>(new RandomAI(gameAttributes, ships)));
        }
        else{
            this->players.push_back(std::unique_ptr<Player>(new HuntDestroyAI(gameAttributes, ships)));
        }
    }
    else{
//        auto player1 = std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships));
//        auto player2 = std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships));
        //this->players.push_back(std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships)));
        int aiType = 0;
        do{
            std::cout << "What AI do you want" << std::endl;
            std::cout << "1. Cheating AI" << std::endl;
            std::cout << "2. Random AI" << std::endl;
            std::cout << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> aiType;
        } while(aiType != 1 && aiType != 2 && aiType != 3);
        if(aiType == 1) {
            this->players.push_back(std::unique_ptr<Player>(new CheatingAI(gameAttributes, ships)));
        }
        else if(aiType == 2){
            this->players.push_back(std::unique_ptr<Player>(new RandomAI(gameAttributes, ships)));
        }
        else{
            this->players.push_back(std::unique_ptr<Player>(new HuntDestroyAI(gameAttributes, ships)));
        }
        aiType = 0;
        do{
            std::cout << "What AI do you want" << std::endl;
            std::cout << "1. Cheating AI" << std::endl;
            std::cout << "2. Random AI" << std::endl;
            std::cout << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> aiType;
        } while(aiType != 1 && aiType != 2 && aiType != 3);
        if(aiType == 1) {
            this->players.push_back(std::unique_ptr<Player>(new CheatingAI(gameAttributes, ships)));
        }
        else if(aiType == 2){
            this->players.push_back(std::unique_ptr<Player>(new RandomAI(gameAttributes, ships)));
        }
        else{
            this->players.push_back(std::unique_ptr<Player>(new HuntDestroyAI(gameAttributes, ships)));
        }
        //this->players.push_back(std::unique_ptr<Player>(new AiPlayer(gameAttributes, ships)));
    }
}

void BattleShip::BattleShipGame::takeTurn(std::vector<std::unique_ptr<BattleShip::Player>>& players, int currentTurn) {
    std::unique_ptr<BattleShip::Player>& player = players[currentTurn];
    int otherTurn = 0;
    if(currentTurn == 1){
        otherTurn = 0;
    }
    else{
        otherTurn = 1;
    }
    //std::unique_ptr<BattleShip::Player>& otherPlayer = players[otherTurn];

    player->getBoard().displayFiring(player->getName());
    player->getBoard().displayPlacement(player->getName());

    Move move = player->getPosition(players[currentTurn], players[otherTurn]);
    player->getBoard().makeMove(move, players[otherTurn], players[currentTurn]->getName());

}

void BattleShip::BattleShipGame::changeTurn(int& currentTurn) {
    if(currentTurn == 0){
        currentTurn = 1;
    }
    else{
        currentTurn = 0;
    }
}

//BattleShip::Move BattleShip::BattleShipGame::getPosition(std::unique_ptr<BattleShip::Player> &player) {
//    return player->getPosition();
//}

bool BattleShip::BattleShipGame::gameOver() {
    int numDestroyedShips = 0;
    for(auto& ship : players[0]->getShipHealths()){
        if(ship.second == 0){
            numDestroyedShips++;
        }
        if(numDestroyedShips == gameAttributes.getNumShips()){
            return true;
        }
    }
    numDestroyedShips = 0;
    for(auto& ship : players[1]->getShipHealths()){
        if(ship.second == 0){
            numDestroyedShips++;
        }
        if(numDestroyedShips == gameAttributes.getNumShips()){
            return true;
        }
    }
    return false;

}

void BattleShip::BattleShipGame::printWinner(int currentTurn) {
    std::cout << players[currentTurn]->getName() <<" won the game!" << std::endl;
}

