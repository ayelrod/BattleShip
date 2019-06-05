//
// Created by Lucas Rodriguez on 2019-06-04.
//

#ifndef BATTLESHIP_HUNTDESTROYAI_H
#define BATTLESHIP_HUNTDESTROYAI_H
#include "AiPlayer.h"

namespace BattleShip {
    class HuntDestroyAI : public AiPlayer{
    public:
        HuntDestroyAI(const GameAttributes& gameAttributes, std::vector<Ship> ships);
        virtual void initializeName();
        void setName(std::string name) override;
        Move getPosition(std::unique_ptr<Player>& otherPlayer) override;
        std::vector<Move> makeVector();
        std::map<Ship, int> getShipHealths() override;

    protected:
        Board board;
        std::map<Ship, int> shipHealths;
        std::string name;
        std::vector<Ship> ships;
    };
}


#endif //BATTLESHIP_HUNTDESTROYAI_H
