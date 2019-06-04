//
// Created by mfbut on 3/9/2019.
//
#include <sstream>
#include <ctime>
#include "Utility.h"
#include "AiPlayer.h"
#include "ShipPosition.h"
#include "CheatingAI.h"
int BattleShip::AiPlayer::nextAiId = 1;
std::mt19937 BattleShip::AiPlayer::randomNumberGenerator((time(nullptr)));



BattleShip::AiPlayer::AiPlayer(const BattleShip::GameAttributes& gameAttributes, std::vector<Ship> ships) :
    Player(gameAttributes, view), aiId(AiPlayer::nextAiId) {
    int aiType = 0;
    do{
        std::cout << "What AI do you want" << std::endl;
        std::cout << "1. Cheating AI" << std::endl;
        std::cout << "2. Random AI" << std::endl;
        std::cout << "3. Hunt Destroy AI" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> aiType;
    } while(aiType != 1 && aiType != 2 && aiType != 3);
    if(aiType == 1){
        CheatingAI(gameAttributes, ships);
    }
    nextAiId++;
}


void BattleShip::AiPlayer::placeShips() {
  std::vector<char> orientation_choice{'h', 'v'};
  const int numRows = getBoard().getNumRows();
  const int numCols = getBoard().getNumCols();

  ShipPosition placement;
  for(const auto& ship : shipHealths) {
    do {
      char orientation = *chooseRandom(orientation_choice, randomNumberGenerator);
      if (orientation == 'h') {
        placement.rowStart = getRandInt(0, numRows - 1, randomNumberGenerator);
        placement.colStart = getRandInt(0, numCols - ship.second, randomNumberGenerator);
        placement.rowEnd = placement.rowStart;
        placement.colEnd = placement.colStart + ship.second - 1;
      } else {
        placement.rowStart = getRandInt(0, numRows - ship.second, randomNumberGenerator);
        placement.colStart = getRandInt(0, numCols - 1, randomNumberGenerator);
        placement.rowEnd = placement.rowStart + ship.second - 1;
        placement.colEnd = placement.colStart;
      }
    }while(!getBoard().canPlaceShipAt(placement));
    getBoard().AddShip(ship.first, placement);
    view.showPlacementBoard(*this);
  }
}

void BattleShip::AiPlayer::initializeName() {
  std::stringstream name;
  name << "AI " << aiId;
  setName(name.str());
}

void BattleShip::AiPlayer::seed_random_number_generator(int seed) {
  BattleShip::AiPlayer::randomNumberGenerator.seed(seed);
}

void BattleShip::AiPlayer::setName(std::string name) {
    return;
}




