//
// Created by evggenshch on 18.07.18.
//


#include "../include/trvFileParser.h"
#include "../include/trvIOContainerWorld.h"


///  +



trvIOContainerWorld::~trvIOContainerWorld () {
  std::for_each(gameObjects.begin(), gameObjects.end(), []( std::pair <std::string, std::shared_ptr <trvEntity> > trvObj) { (*trvObj.second).~trvEntity(); });
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


gPoint * trvIOContainerWorld::getCursor() {
  return &cursor;
}

void trvIOContainerWorld::initAncestorObjects() {     ///    TO-DO:  add normal processing of objects' directory with experimental::filesystem
  FILE * objFile;
  objFile = fopen("../Maps/MainBuilding.trvm", "r");
  this->ancestorObjects.insert(std::make_pair("MainBuilding", trvFileParser::loadEntityFromFile(this, objFile)));
  objFile = fopen("../Maps/CultistEnemy.trvm", "r");
  this->ancestorObjects.insert(std::make_pair("CultistEnemy", trvFileParser::loadEntityFromFile(this, objFile)));
  objFile = fopen("../Maps/FoodFarm.trvm", "r");
  this->ancestorObjects.insert(std::make_pair("FoodFarm", trvFileParser::loadEntityFromFile(this, objFile)));
  objFile = fopen("../Maps/GoldMine.trvm", "r");
  this->ancestorObjects.insert(std::make_pair("GoldMine", trvFileParser::loadEntityFromFile(this, objFile)));
  objFile = fopen("../Maps/MachineGunPoint.trvm", "r");
  this->ancestorObjects.insert(std::make_pair("MachineGunPoint", trvFileParser::loadEntityFromFile(this, objFile)));
}

void trvIOContainerWorld::initMap() {
  FILE * mapFile;
  mapFile = fopen("../Maps/Cadia.trvmp", "r");
  trvFileParser::loadMapFromFile(this, mapFile);
}
trvGameCamera * trvIOContainerWorld::getTrvCamera() {
  return &trvCamera;
}
int trvIOContainerWorld::getGameMode() const {
  return gameMode;
}
void trvIOContainerWorld::setGameMode(int gameMode) {
  this->gameMode = gameMode;
}

void trvIOContainerWorld::changeFoodValue(int changeValue) {
  this->food += changeValue;
}

void trvIOContainerWorld::changeGoldValue(int changeValue) {
  this->gold += changeValue;
}

void trvIOContainerWorld::setBonusFood(int changeValue) {
  this->bonusFood = changeValue;
}

void trvIOContainerWorld::setBonusGold(int changeValue) {
  this->bonusGold = changeValue;
}

int trvIOContainerWorld::getBonusGold() {
  return bonusGold;
}

int trvIOContainerWorld::getBonusFood() {
  return bonusFood;
}

int trvIOContainerWorld::getGoldValue() {
  return gold;
}

int trvIOContainerWorld::getFoodValue() {
  return food;
}

/*  template <typename entityClass, typename... constructorArgs> void trvIOContainerWorld::createEntity(constructorArgs... args) {
  gameObjects.insert(new entityClass(args));
};  */