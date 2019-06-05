//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <map>
//#include "Board.h"
#include "Ship.h"
#include "Move.h"
#include "GameAttributes.h"

namespace BattleShip {
    class Board;
    class Player {
    public:
        Player();
        Player(const GameAttributes& gameAttributes, std::vector<Ship> ships);
        Player(const GameAttributes& gameAttributes, std::vector<Ship> ships, int playerNumber);
        virtual void placeShips();
        virtual void initializeName();
        virtual Board& getBoard();
        virtual std::string getName();
        virtual const int getPlayerType();
        virtual Move getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer);
        virtual std::map<char, int> getShipHealths();
    };
}

#endif //BATTLESHIP_PLAYER_H