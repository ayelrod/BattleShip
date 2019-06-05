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
        virtual void initializeName() override;
        void setName(std::string name) override ;
        void placeShips() override;
        Move getPosition(std::unique_ptr<Player>& otherPlayer) override;
        std::map<Ship, int> getShipHealths() override;
        std::vector<Move> makeVector(std::unique_ptr<Player>& otherPlayer);
    protected:
        Board board;
        std::map<Ship, int> shipHealths;
        std::string name;
        std::vector<Ship> ships;
    };
}


#endif //BATTLESHIP_CHEATINGAI_H
