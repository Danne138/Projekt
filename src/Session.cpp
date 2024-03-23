#include "Session.h"
#include "System.h"
#include <SDL.h>
#include <iostream>
#include <Constants.h>
#include <memory>
#include "Player.h"
#include <chrono>
#include <stdlib.h>
#include "Boulder.h"
#include "Shot.h"
#include "ObjectSpawner.h"
#include <cmath>
#include <vector>
#include <SDL_ttf.h>
using namespace constants;
namespace cwing{
Session::~Session(){



}

void Session::add(Component * comp){

      comps.push_back(comp);

}
void Session::addPlayer(Player * p){


           player=p;
           add(player);

}
void Session::remove(Component * comp){

     for(int x = comps.size() - 1; x >= 0; x--){


        if(comps[x]==comp){

            delete comps[x];
            comps.erase(comps.begin()+x);

        }



}

}
void Session::addSpawn(std::vector<Component *> spawns, int spawnTime){


    ObjectSpawner * spawnSet = new ObjectSpawner(spawns, spawnTime);
    spawningObjects.push_back(spawnSet);

}

bool Session::isShot(Component* comp) {
    return dynamic_cast<Shot*>(comp) != nullptr;
     }

// Helper function to check if the given pointer is of type Boulder
bool Session::isBoulder(Component* comp) {
    return dynamic_cast<Boulder*>(comp) != nullptr;
   }

bool Session::isPlayer(Component* comp) {
    return dynamic_cast<Player*>(comp) != nullptr;
   }
void Session::playerHit(){

    player->isHit();
    hpCounter->changeText("HP: "+std::to_string(player->getHP()));


};

bool Session::containsBoulders(){

    bool containsBoulders = false;
    bool containsSpawns = false;

     for(Component* c: comps){

           if(isBoulder(c)){

              containsBoulders=true;

           }


     }





        for(int x = spawningObjects.size() - 1; x >= 0; x--){

           containsSpawns = spawningObjects[x]->spawnExist();

          if(!containsSpawns){

            delete spawningObjects[x];
            spawningObjects.erase(spawningObjects.begin()+x);


             }


    }





     return containsBoulders||containsSpawns;

}



void Session::getCollision(){






  std::vector<int> indicesToRemove;

      for(int x = comps.size() - 1; x >= 0; x--){



            std::vector<int> xPositions;
            std::vector<int> yPositions;





        xPositions=comps[x]->getXValues();
        yPositions=comps[x]->getYValues();


            for(int y=x-1; y >= 0; y--){




            std::vector<int> secondXPositions=comps[y]->getXValues();
            std::vector<int> secondYPositions=comps[y]->getYValues();



            std::vector<int> xCollision;
            xCollision.resize(std::min(xPositions.size(), secondXPositions.size()));
            auto xEnd = std::set_intersection(xPositions.begin(), xPositions.end(), secondXPositions.begin(), secondXPositions.end(), xCollision.begin());
            std::vector<int> yCollision;
            yCollision.resize(std::min(yPositions.size(), secondYPositions.size()));
            auto yEnd = std::set_intersection(yPositions.begin(), yPositions.end(), secondYPositions.begin(), secondYPositions.end(), yCollision.begin());

            if(xEnd != xCollision.begin() && yEnd != yCollision.begin()){




                if (isShot(comps[y]) && isBoulder(comps[x])){

                          indicesToRemove.push_back(x);
                          indicesToRemove.push_back(y);
                           std::cout<<"Hit!";



               }

               if (isShot(comps[x]) && isBoulder(comps[y])){

                          indicesToRemove.push_back(x);
                          indicesToRemove.push_back(y);
                           std::cout<<"Hit!";



               }

               if (isPlayer(comps[x]) && isBoulder(comps[y])){


                          indicesToRemove.push_back(y);
                          playerHit();


               }

               if (isPlayer(comps[y]) && isBoulder(comps[x])){

                          indicesToRemove.push_back(x);
                          playerHit();




               }






            }












        }



    }


  for (int index : indicesToRemove) {

    remove(comps[index]);

}


}
void Session::breakSes(){

       continueSes=false;

}
void Session::addHpCounter(int x, int y, int w, int h){

    TTF_Font* font = TTF_OpenFont((constants::gResPath+"fonts/Yagora.ttf").c_str(), 24);
    SDL_Color textColor = {255, 255, 255, 255};
    std::string HP = std::to_string(player->getHP());


    hpCounter = new TextBox("HP: "+HP, font, textColor, x,y,w,h);
    add(hpCounter);

}


void Session::addCountDown(int s, int x, int y, int w, int h){

    TTF_Font* font = TTF_OpenFont((constants::gResPath+"fonts/Yagora.ttf").c_str(), 24);
    SDL_Color textColor = {255, 255, 255, 255};
    std::string sString = std::to_string(s);
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point newTime;
    std::chrono::duration<double, std::milli> elapsedTime;

    TextBox * countdown = new TextBox(sString, font, textColor, x,y,w,h);
    add(countdown);


    while(s>0){

           newTime = std::chrono::steady_clock::now();
           elapsedTime = newTime - startTime;


           if(elapsedTime>std::chrono::duration<double, std::milli>(999)){

               s--;

               startTime = std::chrono::steady_clock::now();


               countdown->changeText(std::to_string(s));


           }


    }

  remove(countdown);

}

void Session::addTextBox(int textTime, std::string s, int x, int y, int w, int h){

    TTF_Font* font = TTF_OpenFont((constants::gResPath+"fonts/Yagora.ttf").c_str(), 24);
    SDL_Color textColor = {255, 255, 255, 255};
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point newTime;
    std::chrono::duration<double, std::milli> elapsedTime;
    TextBox * textBox = new TextBox(s, font, textColor, x,y,w,h);
    add(textBox);

    while(textTime>0){

          newTime = std::chrono::steady_clock::now();
          elapsedTime= newTime-startTime;

          if(elapsedTime>std::chrono::duration<double, std::milli>(999.999)){

             startTime = std::chrono::steady_clock::now();

             textTime--;

          }

    }

    remove(textBox);




}

/*void Session::removeOS(ObjectSpawner * os){


        for(int x = spawningObjects.size() - 1; x >= 0; x--){


        if(spawningObjects[x]==os){

            delete spawningObjects[x];
            spawningObjects.erase(spawningObjects.begin()+x);

        }



    }
       delete os;

}*/

int Session::getPlayerHP(){

       return player->getHP();

}

void Session::run() {


    continueSes=true;

    int keyActionCounter = 0;
    prevTime = std::chrono::steady_clock::now();

    bool quit = false;
    bool nestedLoopFinished = false;
    int counter2 = 0;
     if(player->getHP()<1){

        return;
    }

   while (!quit&&continueSes==true) {

    if(player->getHP()<1){

        return;
    }
    SDL_Event eve;


    while (SDL_PollEvent(&eve)) {
        if (eve.type == SDL_QUIT) {
            quit = true;
        }
        else if (eve.type == SDL_MOUSEMOTION) {
            int mouseX = eve.motion.x;
            int mouseY = eve.motion.y;
            for (Component* c : comps) {

                c->updateMousePosition(mouseX, mouseY);

            }
        }
        else if (eve.type == SDL_KEYDOWN) {
          if(keyActionCounter<3){
            if (eve.key.keysym.sym == SDLK_a) {



                for (Component* c : comps) {



                     c->moveLeft(100);


                  }

                    keyActionCounter++;



            }
            else if (eve.key.keysym.sym == SDLK_d) {




                  for (Component* c : comps) {


                     c->moveRight(100);


                  }



                keyActionCounter++;




            }

          }
          else{

              keyActionCounter=0;
              SDL_FlushEvent(SDL_KEYDOWN);



          }
        }
        else if (eve.type == SDL_MOUSEBUTTONDOWN) {
            if (eve.button.button == SDL_BUTTON_LEFT) {


                      double angle=player->getAngle();
                      const double pi = 3.14159265358979323846;
                      double radians = (360.0 - angle+90)*(pi / 180.0);
                      int xPosition = player->getXPosition()+33;
                      int yPosition = player->getYPosition()+55;
                      double coSinus = 50*cos(radians);
                      double sinus = 50*sin(radians);
                      int xNewPoint = xPosition + coSinus;
                      int yNewPoint = yPosition - sinus;
                      Shot* shot = new Shot((constants::gResPath+"images/shot.bmp").c_str(), xNewPoint,yNewPoint, 2, 10, radians,player->getAngle(), 1);
                      ses.add(shot);



            }
        }
        else {

        }
    }

    currentTime = std::chrono::steady_clock::now();
    elapsedTime = currentTime - prevTime;

   if (elapsedTime.count() >= tickInterval) {


      tickCounter++;

      for(ObjectSpawner* os : spawningObjects){

               os->addSpawn();

        }




        if(tickCounter==20){

            getCollision();
            tickCounter=1;
        }


        for (Component* c : comps) {

            c->tick();


        }

        if(!containsBoulders()){

            break;

        }

        SDL_RenderClear(sys.getRen());
        for (Component* c : comps) {


            c->draw();

        }
        if(continueSes==false){

            break;
        }

        SDL_RenderPresent(sys.getRen());
        prevTime = currentTime;
    }
}








}
 Session ses;
}