#include "Constants.h"
#include "System.h"
#include "Session.h"
#include <SDL.h>

namespace cwing{



  System::System(){

        SDL_Init(SDL_INIT_EVERYTHING);

        window = SDL_CreateWindow(

        "SDL2Test",
         100,
         100,
         1125,
         750,
         0
       );

      renderer = SDL_CreateRenderer(window, -1, 0);
      SDL_Surface* background = SDL_LoadBMP((constants::gResPath+"images/Bakgrund.bmp").c_str());
      SDL_Texture* bgTx = SDL_CreateTextureFromSurface(renderer, background);
      SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, bgTx, NULL, NULL);
      SDL_FreeSurface(background);

  };


  System::~System(){

        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();


  }

  SDL_Renderer* System::getRen() const{


        return renderer;


  }
  /*SDL_Surface* System::getSurface() const{


      return background;
  }*/



 System sys;





}
