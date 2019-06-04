//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <map>
#include "Board.h"
#include "Ship.h"

namespace BattleShip {
    class Player {
    public:
        virtual void placeShips();
        virtual void initializeName();
        virtual Board& getBoard();

    protected:
        Board& board;
        std::map<Ship, int> shipHealths;
        std::string name;
        std::vector<Ship> ships;
    };
}


#endif //BATTLESHIP_PLAYER_H
