//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <vector>
#include <string>
#include "GameAttributes.h"
#include "ShipPosition.h"
#include "Ship.h"

namespace BattleShip {
    class Board {
    public:
        Board(const GameAttributes& gameAttributes);
        void displayFiring(std::string name);
        void displayPlacement(std::string name);
        int getNumRows();
        int getNumCols();
        bool canPlaceShipAt(ShipPosition placement);
        void AddShip(const Ship& ship, ShipPosition placement);

    private:
        std::vector<std::string> firingBoard;
        std::vector<std::string> placementBoard;
    };
}

#endif //BATTLESHIP_BOARD_H