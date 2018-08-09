//
// Created by evggenshch on 18.07.18.
//


#include "../include/trvFileParser.h"
#include "../include/trvIOContainerWorld.h"

///  +



trvIOContainerWorld::~trvIOContainerWorld () {
  std::for_each(gameObjects.begin(), gameObjects.end(), []( std::pair <size_t, trvEntity> trvObj) { trvObj.second.~trvEntity(); });
}

int trvIOContainerWorld::getYMapSize() const {
  return yMapSize;
}
void trvIOContainerWorld::setYMapSize(int yMapSize) {
  trvIOContainerWorld::yMapSize = yMapSize;
}
int trvIOContainerWorld::getXMapSize() const {
  return xMapSize;
}
void trvIOContainerWorld::setXMapSize(int xMapSize) {
  trvIOContainerWorld::xMapSize = xMapSize;
}

int trvIOContainerWorld::getCurrentGameMode() {
  return currentGameMode;
}

void trvIOContainerWorld::initAncestorObjects() {     ///    TO-DO:  add normal processing of objects' directory with experimental::filesystem
  FILE * objFile;
  objFile = fopen("../Maps/MainBuilding.trvm", "r");
  trvFileParser::loadEntityFromFile(this, objFile);
  objFile = fopen("../Maps/CultistEnemy.trvm", "r");
  trvFileParser::loadEntityFromFile(this, objFile);
  objFile = fopen("../Maps/FoodFarm.trvm", "r");
  trvFileParser::loadEntityFromFile(this, objFile);
  objFile = fopen("../Maps/GoldMine.trvm", "r");
  trvFileParser::loadEntityFromFile(this, objFile);
  objFile = fopen("../Maps/MachineGunPoint.trvm", "r");
  trvFileParser::loadEntityFromFile(this, objFile);
}

void trvIOContainerWorld::initMap() {
  FILE * mapFile;
  mapFile = fopen("../Maps/Cadia.trvmp", "r");
  trvFileParser::loadMapFromFile(this, mapFile);
}


/*  template <typename entityClass, typename... constructorArgs> void trvIOContainerWorld::createEntity(constructorArgs... args) {
  gameObjects.insert(new entityClass(args));
};  */