//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvFileParser.h"

trvEntity * trvFileParser::loadEntityFromFile(trvIOContainerWorld * gameWorld, FILE * entityFile) {
  char className[100];
  gComponent currentComponent;
  std::vector <gComponent> entityComponents;
  fscanf(entityFile, "%s", className);
  while(!feof(entityFile)) {
     currentComponent = loadComponentFromFile(gameWorld, entityFile);
     entityComponents.push_back(currentComponent);
  }
  return gameWorld->initObjects.find(std::string(className))->second(entityComponents);
}

gComponent * trvFileParser::loadComponentFromFile(trvIOContainerWorld * gameWorld, FILE * componentFile) {
  char componentName[100];
  fscanf(componentFile, "%s", componentName);
  return this->readComponent.find(std::string(componentName))->second(componentFile);
}

void trvFileParser::loadMapFromFile(trvIOContainerWorld * gameWorld, FILE * mapFile) {
  int ySize, xSize;
  fscanf(mapFile, "%i %i", ySize, xSize);
  gameWorld->setYMapSize(ySize);
  gameWorld->setXMapSize(xSize);
  char className[100];
  while(!feof(mapFile)) {
    fscanf(mapFile, "%s", className);
    gameWorld->copyObjects.find(std::string(className))->second(gameWorld->ancestorObjects.find(className));
    gameWorld->gameObjects.insert(std::pair <objToInsert->get_hash(),  objToInsert> );
  }
}