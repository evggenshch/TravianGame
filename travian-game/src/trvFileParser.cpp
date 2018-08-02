//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvFileParser.h"

gEntity * trvFileParser::loadEntityFromFile(trvIOContainerWorld * gameWorld, FILE * entityFile) {
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