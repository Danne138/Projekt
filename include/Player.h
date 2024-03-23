#ifndef PLAYER_H
#define PLAYER_H
#include <System.h>
#include <Component.h>
#include <vector>


namespace cwing{


    class Player: public Component{


       public:


         Player(std::string imagePath, int x, int y, int w, int h, int speed, int hp);
         void draw();
         void moveLeft(int distance);
         void moveRight(int distance);
         virtual void moveUp(int distance);
         virtual void moveDown(int distance);
         void updateMousePosition(int x, int y);
         void updateAngle();
         void shooting();
         void setLeft();
         void setRight();
         void setUp();
         void setDown();
         void tick();
         int getHP();
         int getPlayerXPostion();
         int getPlayerYPostion();
         std::vector<int> getXValues();
         std::vector<int> getYValues();
         double getAngle();
         double getRadians();
         void isHit();
         Player(std::string imagePath,int x, int y, int w, int h, int speed);
         virtual ~Player();


       protected:



       private:


           int mousePositionX;
           int mousePositionY;
           int HP;
           int leftCounter;
           int rightCounter;
           int upCounter;
           int downCounter;
           int angle;
           int speed;
           double radians;
           int speedCounter;
           std::string picturePathWay;
           SDL_Texture* texture;
           SDL_Surface* surface;





};







}
#endif