//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvFileParser.h"

/**  Memory allocation starts here  **/


std::shared_ptr <trvEntity> trvFileParser::loadEntityFromFile(trvIOContainerWorld * gameWorld, FILE * entityFile) {
  char className[100];
  std::vector < std::unique_ptr <gComponent> > entityComponents;
  fscanf(entityFile, "%s", className);
  while(!feof(entityFile)) {
     auto currentComponent = loadComponentFromFile(gameWorld, entityFile);
     entityComponents.push_back(std::move(currentComponent));
  }
  fclose(entityFile);
  return gameWorld->initObjects.find(std::string(className))->second(std::move(entityComponents));
}

std::unique_ptr <gComponent> trvFileParser::loadComponentFromFile(trvIOContainerWorld * gameWorld, FILE * componentFile) {
  char componentName[100];
  fscanf(componentFile, "%s", componentName);
  return gameWorld->readComponent.find(std::string(componentName))->second(componentFile);
}

void trvFileParser::loadMapFromFile(trvIOContainerWorld * gameWorld, FILE * mapFile) {
  int ySize, xSize;
  gameWorld->initAncestorObjects();
  fscanf(mapFile, "%i %i\n", &ySize, &xSize);
  gameWorld->setYMapSize(ySize);
  gameWorld->setXMapSize(xSize);
///  std::map <std::string, std::shared_ptr <trvEntity> > testObjects = { {"Sample", nullptr}  };
  while(!feof(mapFile)) {

    char className[100];
    fscanf(mapFile, "%s", className);
    std::string stringName(className);
    std::shared_ptr <trvEntity> newObj = gameWorld->copyObjects.find(stringName)->second(stringName, &gameWorld->ancestorObjects);

    auto gPtr = loadComponentFromFile(gameWorld, mapFile);

    (*newObj).setPos(std::move(gPtr));

    gameWorld->gameObjects.insert(std::pair <std::string, std::shared_ptr <trvEntity> >
    (stringName, std::move(newObj)));
  }
  fclose(mapFile);
}

  // shared_ptr   = gameWorld->copyObjects.find(std::string(className))->second(std::string(className), gameWorld->ancestorObjects);