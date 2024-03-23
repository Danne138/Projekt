#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include "System.h"
#include <cmath>
#include <vector>




namespace cwing{

  class Component{


        public:


           virtual ~Component();
           int getXPosition();
           int getYPosition();
           double xDouble;
           virtual void draw() = 0;
           virtual void mouseDown(const SDL_Event& eve){};
           void setX(int value);
           void setY(int value);
           void moveX(int value);
           void moveY(int value);
           virtual void tick(){};
           virtual void setLeft(){};
           virtual void setRight(){};
           virtual void moveLeft(int distance){};
           virtual void moveRight(int distance){};
           virtual void moveUp(int distance){};
           virtual void moveDown(int distance){};
           virtual void shooting(){};
           virtual void updateMousePosition(int x, int y){};
           virtual void setTrajectory(){};
           virtual double getAngle(){};
           virtual void updateAngle(){};
           double getRadians(){};
           virtual std::vector<int> getXValues(){};
           virtual std::vector<int> getYValues(){};
           void fillRect();
           SDL_Rect& getRect(){ return rect;}

        protected:

             Component(int x, int y, int w, int h);
             SDL_Surface * surface;
             std::string imagePath;

        private:


           bool isWholeNumber(double value);
           SDL_Rect rect;
           Component(const Component&) = delete;
           const Component& operator=(const Component&) = delete;
};

}
#endif