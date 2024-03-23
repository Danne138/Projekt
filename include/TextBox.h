#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "Projectile.h"
#include <SDL_ttf.h>
#include "Component.h"
#include <string>

namespace cwing{


  class TextBox: public Component{

      public:

      TextBox(std::string s, TTF_Font * font, SDL_Color color, int x, int y, int w, int h);
      void draw();
      void tick(){};
      void changeText(std::string newText);
      std::vector<int> getXValues();
      std::vector<int> getYValues();
      virtual ~TextBox();


      private:

       SDL_Texture * text;
       std::string s;
       TTF_Font * font;
       SDL_Color color;








  };



}
#endif