//
// Created by Lucas Rodriguez on 2019-06-04.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"


namespace BattleShip {
    class CheatingAI : public AiPlayer {
    public:
        CheatingAI(const GameAttributes& gameAttributes, std::vector<Ship> ships);
        virtual void initializeName();
        void setName(std::string name) override ;
        void placeShips() override;
        Move getPosition() override;
        std::map<Ship, int> getShipHealths() override;
    protected:
        Board board;
        std::map<Ship, int> shipHealths;
        std::string name;
        std::vector<Ship> ships;
    };
}


#endif //BATTLESHIP_CHEATINGAI_H
