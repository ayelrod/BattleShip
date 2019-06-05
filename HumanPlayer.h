//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
#include "Board.h"

namespace BattleShip {
    class HumanPlayer : public Player {
    public:
        HumanPlayer(const GameAttributes& gameAttributes, std::vector<Ship>& ships, int playerNumber);
        void placeShips() override;
        std::string getName() override;
        Move getPosition(std::unique_ptr<Player>& otherPlayer);
        BattleShip::Board& getBoard() override;
        bool validMove(int row, int col);
        std::map<char, int> getShipHealths() override;
        
    protected:
        Board board;
        std::map<char, int> shipHealths;
        std::string name;
        std::vector<BattleShip::Ship> ships;

    };
}


#endif //BATTLESHIP_HUMANPLAYER_H
