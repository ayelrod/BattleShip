//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "Player.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"

BattleShip::Player::Player(GameAttributes& gameAttributes, std::vector<Ship> ships) {
    AiPlayer();
}

BattleShip::Player::Player(BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships,
                           int playerNumber) {
    HumanPlayer(gameAttributes, ships, playerNumber);
}
