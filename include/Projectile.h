#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <Component.h>
#include <System.h>
#include <SDL.h>
#include <vector>




  namespace cwing{




   class Projectile: public Component{



        public:

           Projectile(int x, int y, int w, int h, int speed);
           virtual ~Projectile(){};
           virtual void draw() = 0;
           virtual std::vector<int> getXValues(){};
           virtual std::vector<int> getYValues(){};
           void tick();




       protected:


          SDL_Texture* texture;
          double angle;
          double angleInDegrees;
          double cosinus;
          double sinus;
          int speed;
          int startX;
          int startY;
          int endX;
          int endY;
          double radians;
          int speedCounter;
          int mousePositionX;
          int mousePositionY;





};
}
 #endif