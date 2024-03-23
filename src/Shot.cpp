#include "Shot.h"
#include "Projectile.h"
#include <Constants.h>
#include "Session.h"
#include <SDL.h>
#include <cmath>
#include <iostream>

using namespace constants;
namespace cwing{


  Shot::Shot(std::string imagePath, int x, int y, int w, int h,double degreesInRadians, int angleInDegrees, int speed): Projectile(x,y,w,h, speed), degreesInRadians(degreesInRadians), angleInDegrees(angleInDegrees), startingPositionX(x), startingPositionY(y){





           cosinus = 2*cos(degreesInRadians);
           sinus = 2*sin(degreesInRadians);
           surface = SDL_LoadBMP((imagePath).c_str());
           texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
          SDL_FreeSurface(surface);


  }


  void Shot::draw(){




            SDL_RendererFlip flip =  SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(sys.getRen(), texture, NULL , &getRect(), angleInDegrees, NULL, flip);



  }

      std::vector<int> Shot::getXValues(){


        std::vector<int> xValues;




           for(int width=0; width<getRect().w; width++){


              int newX=getRect().x-static_cast<int>(cosinus*width);
              xValues.push_back(newX);



           }



        return xValues;



      };

    std::vector<int> Shot::getYValues(){

     std::vector<int> yValues;


     for(int height=0; height<getRect().h; height++){

      int newY=getRect().y+static_cast<int>(sinus*height);
      yValues.push_back(newY);


     }

    return yValues;

    };



  void Shot::tick(){


            speedCounter--;
            if(speedCounter==0){

                tickCounter++;
                int xNewPoint = startingPositionX + tickCounter*cosinus;
                int yNewPoint = startingPositionY - tickCounter*sinus;
                setX(xNewPoint);
                setY(yNewPoint);
                speedCounter=speed;




            }

            if(getRect().x>1130||getRect().x<0||getRect().y<-5||getRect().y>755){

                   ses.remove(this);
                

            }


  }

  Shot::~Shot(){


    SDL_DestroyTexture(texture);

  };





}