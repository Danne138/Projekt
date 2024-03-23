#ifndef BOULDER_H
#define BOULDER_H
#include "Projectile.h"
#include <vector>



namespace cwing{

  class Boulder: public Projectile{

      public:

        Boulder(std::string pathWay,int x, int y,int endX, int endY, int w, int h, int speed);
        virtual ~Boulder();
        void draw();
        void tick();
        std::vector<int> getXValues();
        std::vector<int> getYValues();

      private:

        int spawnTimer;
        int endX;
        int endY;
        int tickCounter=1;
        int startingPositionX;
        int startingPositionY;



  };


}
#endif