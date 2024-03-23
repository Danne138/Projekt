#include <Player.h>
#include <System.h>
#include <Constants.h>
#include <cmath>
#include <iostream>
#include <Session.h>
#include <string>
#include <SDL.h>



using namespace constants;


namespace cwing{



   Player::Player(std::string imagePath,int x, int y, int w, int h, int speed, int hp): Component(x, y, w, h), HP(hp), speed(speed), speedCounter(speed){



           surface = SDL_LoadBMP(imagePath.c_str());
           texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
           SDL_FreeSurface(surface);




}

   Player::~Player(){





   }

   void Player::moveLeft(int distance){

        leftCounter=distance;

   }
   void Player::moveRight(int distance){

       rightCounter=distance;

   }
   void Player::moveUp(int distance){

        upCounter=distance;

   };
   void Player::moveDown(int distance){

        downCounter=distance;


   };

   int Player::getHP(){

        return HP;

   }

  void Player::isHit(){


       HP--;

       if(HP==0){

           std::cout<<"lol";
           ses.remove(this);
           ses.breakSes();

       }

  }


   void Player::draw(){



            SDL_RendererFlip flip =  SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(sys.getRen(), texture, NULL , &getRect(), angle, NULL, flip);




   }

   std::vector<int> Player::getXValues(){


      std::vector<int> xValues;




     for(int width=0; width<getRect().w; width++){

              xValues.push_back(getRect().x+width);


           }



        return xValues;



};
std::vector<int> Player::getYValues(){

     std::vector<int> yValues;


     for(int height=0; height<getRect().h; height++){

      int newY=getRect().y+height;
      yValues.push_back(newY);

     }

    return yValues;


};

  void Player::updateAngle(){

            int oldX = getRect().x;
            int oldY = getRect().y;

            double dx = mousePositionX - oldX-32; // calculate differences in x and y coordinates
            double dy = mousePositionY - oldY-55;
            radians = atan2(dy,dx);
            angle = atan2(dy, dx) * 180 / M_PI; // calculate angle in radians and convert to degrees
            angle = fmod(angle + 180, 360);
            angle = angle-90;


 // adjust to the range 0 to 360 degrees

   }



   void Player::updateMousePosition(int x, int y){



          mousePositionX = x;
          mousePositionY = y;
          updateAngle();

   }

   void Player::setLeft(){


             moveX(-1);
             updateAngle();

   }
   void Player::setRight(){


             moveX(1);
             updateAngle();

   }
   void Player::setUp(){


             moveY(-1);
             updateAngle();

    }

    void Player::setDown(){


            moveY(1);
            updateAngle();

    }

   double Player::getRadians(){

       return radians;

   }

   void Player::shooting(){

   /*
        Shot* shot = new Shot(getRect().x,getRect().y, 10, 2, getAngle());
        ses.add(shot);

  */

   }
   double Player::getAngle(){

     return angle;

   }

   int Player::getPlayerXPostion(){


           return getRect().x;


   }
   void Player::tick(){


            if(leftCounter>0&&getRect().x>0){

               setLeft();
               leftCounter--;
            }
            if(rightCounter>0&&getRect().x<1030){

              setRight();
              rightCounter--;

            }
         



   }

   int Player::getPlayerYPostion(){


          return getRect().y;

   }











}
