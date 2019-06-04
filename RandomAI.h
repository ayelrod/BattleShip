//
// Created by Lucas Rodriguez on 2019-06-04.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H
#include "AiPlayer.h"

namespace BattleShip{
    class RandomAI : public AiPlayer {
    public:
    protected:
        Board board;
        std::map<Ship, int> shipHealths;
        std::string name;
        std::vector<Ship> ships;
    };
}

#endif //BATTLESHIP_RANDOMAI_H
