//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"

namespace BattleShip {
    class HumanPlayer : public Player {
    public:
        HumanPlayer(const GameAttributes& gameAttributes, std::vector<Ship> ships, int playerNumber);
        void placeShips() override;
        std::string getName() override;
        Move getPosition(std::unique_ptr<Player>& otherPlayer);
        bool validMove(int row, int col);
        std::map<Ship, int> getShipHealths() override;
    protected:
        Board board;
        std::map<Ship, int> shipHealths;
        std::string name;
        std::vector<Ship> ships;
    };
}


#endif //BATTLESHIP_HUMANPLAYER_H
