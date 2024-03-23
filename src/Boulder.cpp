#include "Boulder.h"
#include "Projectile.h"
#include "Session.h"
#include <Constants.h>
#include <SDL.h>

using namespace constants;
namespace cwing{


Boulder::Boulder(std::string pathWay,int x, int y,int endX, int endY, int w, int h, int speed): Projectile(x,y,w,h, speed), endX(endX), endY(endY),startingPositionX(x), startingPositionY(y){

           double dx = endX - startX; // calculate differences in x and y coordinates
           double dy = endY - startY;
           double radians = atan2(dy,dx);
           cosinus = static_cast<int>(2*cos(radians));
           sinus = static_cast<int>(2*sin(radians));
           radians = radians+0.5*M_PI;
           double angle = radians * 180 / M_PI;
           angle=angle-angle*angle;
           surface = SDL_LoadBMP(pathWay.c_str());
           texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
           SDL_FreeSurface(surface);


}


void Boulder::tick(){



            speedCounter--;
            if(speedCounter==0){

                tickCounter++;
                int xNewPoint = startingPositionX + tickCounter*cosinus;
                int yNewPoint = startingPositionY + tickCounter*sinus;
                setX(xNewPoint);
                setY(yNewPoint);
                speedCounter=speed;


            }
            if(getRect().x>1130||getRect().x<0||getRect().y<-5||getRect().y>755){


                   ses.remove(this);


            }
            if(getRect().y>755){

                  ses.playerHit();

            }



}

std::vector<int> Boulder::getXValues(){


      std::vector<int> xValues;




     for(int width=0; width<getRect().w; width++){

              xValues.push_back(getRect().x+width);


           }



        return xValues;



};
std::vector<int> Boulder::getYValues(){

     std::vector<int> yValues;


     for(int height=0; height<getRect().h; height++){

      int newY=getRect().y+height;
      yValues.push_back(newY);

     }

    return yValues;


};


void Boulder::draw(){



            SDL_RendererFlip flip =  SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(sys.getRen(), texture, NULL , &getRect(), angleInDegrees, NULL, flip);


}

Boulder::~Boulder(){

     SDL_DestroyTexture(texture);

}



}