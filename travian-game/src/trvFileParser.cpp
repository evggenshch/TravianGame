//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvFileParser.h"

gEntity * trvFileParser::loadEntityFromFile(trvIOContainerWorld * gameWorld, FILE * entityFile) {
  char className[100];
  fscanf(entityFile, "%s", className);
  gameWorld->createEntity(std::string(className);
  return gameWorld->;
}