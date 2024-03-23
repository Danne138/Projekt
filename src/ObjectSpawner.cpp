#include "ObjectSpawner.h"
#include <vector>
#include "Component.h"
#include "Session.h"

namespace cwing{



 ObjectSpawner::ObjectSpawner(std::vector<Component *> spawns, int spawnTime):spawns(spawns), spawnTime(spawnTime),spawnTimer(spawnTime) {

}

void ObjectSpawner::addSpawn(){

      spawnTimer--;
      if(spawnTimer==0&&!spawns.empty()){


         ses.add(spawns[0]);
         spawns.erase(spawns.begin());
         spawnTimer=spawnTime;

      }



}
bool ObjectSpawner::spawnExist(){


     return !spawns.empty();

}






}