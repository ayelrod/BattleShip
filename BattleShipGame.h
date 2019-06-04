//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_BATTLESHIPGAME_H
#define BATTLESHIP_BATTLESHIPGAME_H
#include <vector>
#include "GameAttributes.h"
#include "HumanPlayer.h"

namespace BattleShip {
    class BattleShipGame {
    public:
        BattleShipGame(int numRows, int numCols, int numShips, std::vector<char>& shipChars,
                       std::vector<int>& shipSizes, int gameType, int seed);
        void playGame();
        void initializePlayers(GameAttributes& gameAttributes);
    private:
        std::vector<Player*> players;
        int currentTurn;
        GameAttributes gameAttributes;
    };
}

#endif //BATTLESHIP_BATTLESHIPGAME_H
