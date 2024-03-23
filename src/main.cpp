#include <iostream>
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <System.h>
#include <SDL_image.h>
#include <Constants.h>
#include <cmath>
#include "Player.h"
#include "Session.h"
#include "Game.h"

using namespace cwing;


int main(int argc, char* args[])
{

  using namespace constants;
  SDL_Init(SDL_INIT_EVERYTHING);
  if ( TTF_Init() < 0 ) {
	std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
}





   Game * game = new Game();

   game->gameLoop();


  TTF_Quit();
  SDL_Quit();
  return 0;
}
