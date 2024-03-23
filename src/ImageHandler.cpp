#include "ImageHandler.h"
#include <SDL.h>
#include <string>
namespace cwing{












ImageHandler::ImageHandler(std::string pathway){


             SDL_Surface* surface = SDL_LoadBMP(pathway.c_str());

}

int ImageHandler::getHeight(){

    return surface->h;


}
int ImageHandler::getWidth(){

    return surface->w;

}







}