#include "TextBox.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Component.h"
#include "Constants.h"
using namespace constants;
namespace cwing{


    TextBox::TextBox(std::string s, TTF_Font * font, SDL_Color color, int x, int y, int w, int h): Component(x,y,w,h), color(color), font(font){

           SDL_RenderClear(sys.getRen());
           surface = TTF_RenderText_Solid(font, s.c_str(), color);
           text = SDL_CreateTextureFromSurface(sys.getRen(), surface);
           SDL_RenderCopy(sys.getRen(), text, NULL, &getRect());
           SDL_FreeSurface(surface);
           SDL_RenderPresent(sys.getRen());




    }

      std::vector<int> TextBox::getXValues(){


          std::vector<int> empty;
          return empty;



      };
      std::vector<int> TextBox::getYValues(){

          std::vector<int> empty;
          return empty;

      };

    void TextBox::changeText(std::string newText){


           SDL_DestroyTexture(text);
           surface = TTF_RenderText_Solid(font, newText.c_str(), color);
           text = SDL_CreateTextureFromSurface(sys.getRen(), surface);
           SDL_RenderClear(sys.getRen());
           SDL_RenderCopy(sys.getRen(), text, NULL, &getRect());
           SDL_RenderPresent(sys.getRen());
           SDL_FreeSurface(surface);



    }

    void TextBox::draw(){



      SDL_RenderCopy(sys.getRen(), text, NULL, &getRect());




    }

    TextBox::~TextBox(){

     SDL_DestroyTexture(text);
     SDL_FreeSurface(surface);
     TTF_CloseFont(font);

}





}
