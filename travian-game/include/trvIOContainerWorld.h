//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_WORLD_H
#define EVGENIJ_SCHERBAKOV_GAME_WORLD_H

#include "../include/player.h"
#include <include/gComponent.h>
#include "include/gMap.h"
#include "trvEntityMainBuilding.h"

class trvIOContainerWorld {
 private:
  /*   std::map <std::string, std::function<gEntity*()>> initObjects = {
      {"MainBuilding",[](){return new trvEntityMainBuilding;}}
  };  */
  //   bool entitiesInitiated = false;

  ///      загрузка порождающих и копирующих конструкторов в map

  std::map <std::string, std::function<gEntity*(std::vector <gCom>)> > initObjects = {
      {"MainBuildingCreate", []()}

  };
  std::unordered_multimap <size_t, gEntity> gameObjects;  //  multimap?
  int currentGameMode = gCore::MENU_MODE;
  ///  ДОСТУП К ОБЪЕКТУ??????  --  объект хранит свои координаты

  player user;
  gMap game_map;
  int map_count = 1;
 public:
  //   unsigned int seed_1 = 1, seed_2 = 2, seed_3 = 3;
  trvIOContainerWorld(player input_user,  gMap input_game_map) :  user(input_user), game_map(input_game_map) {
    user = input_user;
    game_map = input_game_map;
  }
  //   template <typename entityClass, typename... constructorArgs> void createEntity(constructorArgs... args);
  player & get_players();
  int getCurrentGameMode();
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_WORLD_H
