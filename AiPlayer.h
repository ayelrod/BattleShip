//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_AIPLAYER_H
#define BATTLESHIP_AIPLAYER_H
#include <random>
#include "Player.h"


namespace BattleShip {
class Move;
class AiPlayer : public Player {
 public:
  AiPlayer(const BattleShip::GameAttributes& gameAttributes, std::vector<Ship> ships);
  static void seed_random_number_generator(int seed);
  virtual void placeShips() override;
  virtual void initializeName() override;
  virtual void setName(std::string name);


 protected:
  static std::mt19937 randomNumberGenerator;

 private:
  static int nextAiId;
  const int aiId;

};
}
#endif //BATTLESHIP_AIPLAYER_H
