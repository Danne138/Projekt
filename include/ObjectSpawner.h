#ifndef OBJECTSPAWNER_H
#define OBJECTSPAWNER_H
#include "Projectile.h"
#include "Component.h"
#include <vector>



namespace cwing{

  class ObjectSpawner{

      public:

        ObjectSpawner(std::vector<Component *> spawns, int spawnTime);
        ~ObjectSpawner(){};
        void addSpawn();
        bool spawnExist();



      private:



        int amount;
        int spawnTime;
        int spawnTimer;
        std::vector<Component *> spawns;



  };


}
#endif