#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Component.h"
#include <chrono>
#include "ObjectSpawner.h"
#include <algorithm>
#include <player.h>
#include <TextBox.h>
#include <string>



namespace cwing{


 class Session{

   public:

     void add(Component * comp);
     void remove(Component * comp);
     void run();
     void tick();
     void addSpawn(std::vector<Component *> spawns, int spawnTime);
     void getCollision();
     void addPlayer(Player * p);
     void breakSes();
     void playerHit();
     void addTextBox(int textTime,std::string s, int x, int y, int w, int h);
     void addHpCounter(int x, int y, int w, int h);
     void addCountDown( int s, int x, int y, int w, int h);
     void removeOS(ObjectSpawner* os);
     bool containsBoulders();
     int getPlayerHP();
     ~Session();

   private:

     bool continueSes = true;
     int counter = 0;
     int boulderSpeed = 0;
     int tickCounter = 1;
     TextBox * hpCounter;
     Player * player;
     std::vector<Component *> comps;
     std::vector<ObjectSpawner *> spawningObjects;
     const double tickRate = 500;
     const double tickInterval = 1000.0 / tickRate;
     Component * lifeText;
     Component * startingText;
     std::chrono::steady_clock::time_point currentTime;
     std::chrono::steady_clock::time_point prevTime;
     std::chrono::duration<double, std::milli> elapsedTime;
     bool isShot(Component* comp);
     bool isBoulder(Component* comp);
     bool isPlayer(Component* comp);


 };

  extern Session ses;
}
 #endif