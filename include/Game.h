#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Component.h"



namespace cwing{



class Game{



   private:

      int boulderCounter = 0;
      std::vector<Component *> boulders;
      int level = 1;
      int spawnTime = 500;
      double boulderSpeed = 10;
      int numberOfBoulders = 10;
      bool continueLoop = 1;




   public:

      Game(){};
      ~Game();
      void gameLoop();



};





}
#endif