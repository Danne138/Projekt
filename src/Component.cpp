#include "Component.h"
#include "System.h"
#include "Session.h"
#include <cmath>
#include <iostream>




namespace cwing{


   Component::Component(int x, int y, int w, int h): rect{x,y,w,h}{




   }


    Component::~Component(){


          


   }
   int Component::getXPosition(){

       return rect.x;

   }
   int Component::getYPosition(){

       return rect.y;

   }

   void Component::fillRect(){

       SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
       SDL_RenderFillRect(sys.getRen(), &rect);

   }



  bool Component::isWholeNumber(double value)
   {
    double remainder = std::fmod(value, 1.0);
    return remainder == 0.0;
    }


  void Component::moveX(int value){


            rect.x+=value;

   }

  void Component::moveY(int value){

          rect.y+=value;


   }
   void Component::setX(int value){

           rect.x=value;

   }
   void Component::setY(int value){

         rect.y=value;

   }









}