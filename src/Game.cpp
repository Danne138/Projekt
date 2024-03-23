#include "Game.h"
#include "Constants.h"
#include "player.h"
#include "Boulder.h"
#include "ImageHandler.h"
#include "Session.h"
#include <string>
namespace cwing{

 using namespace constants;

  void Game::gameLoop(){


    std::string raketPath = (constants::gResPath+"images/Raket.bmp").c_str();
    std::string white = (constants::gResPath+"images/shot.bmp").c_str();
    std::string boulderPath = (constants::gResPath+"images/boulder.bmp").c_str();




    Player* player = new Player(raketPath, 525, 625, 67, 116, 5, 5);
    ses.addPlayer(player);
    ses.addHpCounter(10, 10, 60, 40);

    /*ses.addTextBox(2, "Game starting soon. Get ready! Level: "+std::to_string(level), 350 ,350, 500, 50);
*/





     while(continueLoop==true&&ses.getPlayerHP()>1){






      for(int x=0; x<numberOfBoulders; x++){

          int randomXStart = rand() % 1100+1;
          int randomXEnd = rand() % 1100+1;
          int newSpeed = static_cast<int>(boulderSpeed);
          Boulder* boulder = new Boulder(boulderPath ,randomXStart, 0, randomXEnd, 750, 78, 57, newSpeed);

          boulders.push_back(boulder);


     }


        ses.addSpawn(boulders, spawnTime);



       /* ses.addCountDown(5, 525 ,350, 50, 50);

        ses.addTextBox(1, "Game starting!", 400 ,350, 300, 50);
*/
        ses.run();

        if(!ses.containsBoulders()){

          level++;
          /*ses.addTextBox(2, "Level complete! Get ready! Level: "+std::to_string(level), 400 ,350, 400, 50);*/
          numberOfBoulders+=2;
          spawnTime-=20;
          boulderSpeed-=0.25;




        }
        if(ses.getPlayerHP()<0){


           continueLoop=false;
           return;

        }



        boulders.clear();
     }




  }






}