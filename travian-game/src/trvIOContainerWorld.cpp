//
// Created by evggenshch on 18.07.18.
//

#include "../include/trvIOContainerWorld.h"

player & trvIOContainerWorld::get_players() {
  return user;
}

int trvIOContainerWorld::getCurrentGameMode() {
  return currentGameMode;
}



/*  template <typename entityClass, typename... constructorArgs> void trvIOContainerWorld::createEntity(constructorArgs... args) {
  gameObjects.insert(new entityClass(args));
};  */