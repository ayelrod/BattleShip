//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "HumanPlayer.h"

BattleShip::HumanPlayer::HumanPlayer(BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships, int playerNumber) : ships(ships)
    board(gameAttributes){
    //initialize boards


    //get name
    std::cout << "Player " << playerNumber << ", please enter your name: ";
    std::cin >> this->name;

    for(int i = 0; i < ships.size(); i++){
        shipHealths[ships[i]] = gameAttributes.getShipSizes()[i];
    }
}
