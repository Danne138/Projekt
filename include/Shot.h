#ifndef SHOT_H
#define SHOT_H
#include "Projectile.h"
namespace cwing{


  class Shot: public Projectile{

      public:

      Shot(std::string imagePath, int x, int y, int w, int h,double degreesInRadians, int angleInDegrees, int speed);
      void draw();
      void tick();
      std::vector<int> getXValues();
      std::vector<int> getYValues();
      virtual ~Shot();


      private:

        double degreesInRadians;
        int angleInDegrees;
        int tickCounter=1;
        int startingPositionX;
        int startingPositionY;




  };



}
#endif