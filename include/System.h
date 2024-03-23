#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <string>
namespace cwing{



 class System{


    public:

       System();
       ~System();
       SDL_Renderer* getRen() const;
       SDL_Surface* getSurface() const;

    private:

         SDL_Window * window;
         SDL_Renderer * renderer;
         SDL_Surface * background;
         SDL_Texture* bgTx;
    };

  extern System sys;



}


#endif