#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H
#include <SDL.h>
#include <string>




namespace cwing{



    class ImageHandler{






        public:

            ImageHandler(std::string pathway);
            int getWidth();
            int getHeight();


        private:

          SDL_Surface * surface;









   };













}

#endif