//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_WORLD_H
#define EVGENIJ_SCHERBAKOV_GAME_WORLD_H

#include "../include/player.h"
#include <include/gComponent.h>
#include "include/gMap.h"
#include "trvEntityMainBuilding.h"
#include "trvEntityMachineGunPoint.h"
#include "trvEntityEnemyCultist.h"
#include "trvEntityFoodFarm.h"
#include "trvEntityGoldMine.h"
//   #include "trvE"

typedef std::vector <gComponent> entityConstructorArg;

template <typename T> T* entityInit(entityConstructorArg entityParams) {
  return new T(entityParams);
}

template <typename T> T* entityCopy(T* entityToCopy) {
  T entityCopy = new T;
  entityCopy = &entityToCopy;
  return &entityCopy;
}

class trvIOContainerWorld {
 private:
  /*   std::map <std::string, std::function<gEntity*()>> initObjects = {
      {"MainBuilding",[](){return new trvEntityMainBuilding;}}
  };  */
  //   bool entitiesInitiated = false;

  ///      загрузка порождающих и копирующих конструкторов в map



  int currentGameMode = gCore::MENU_MODE;
  ///  ДОСТУП К ОБЪЕКТУ??????  --  объект хранит свои координаты

  player user;
  gMap game_map;

 public:

  //      {"MainBuildingInit", []  (entityConstructorArg entityParams) { return new trvEntityMainBuilding(); }},
  std::unordered_multimap <size_t, gEntity> gameObjects;  //  multimap?

  std::map <std::string, std::function<gEntity*(entityConstructorArg)> > initObjects = {
      {"MainBuildingInit", entityInit<trvEntityMainBuilding>},
      {"MachineGunPointInit", entityInit<trvEntityMachineGunPoint>},
      {"EnemyCultistInit", entityInit<trvEntityEnemyCultist>},
      {"FoodFarmInit", entityInit<trvEntityFoodFarm>},
      {"GoldMineInit", entityInit<trvEntityGoldMine>}
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},,
  };
  //    std::map <> =
  /*     std::map <std::string, std::function > initComponents = {
      {"GraphicalComponent", },
      {"HealthComponent", }
  };   */
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
