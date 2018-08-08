//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_TRVIOCONTAINERWORLD_H
#define EVGENIJ_SCHERBAKOV_TRVIOCONTAINERWORLD_H

//   #include "../include/"
#include <include/gComponent.h>
#include "include/gMap.h"
#include "trvEntityMainBuilding.h"
#include "trvEntityMachineGunPoint.h"
#include "trvEntityEnemyCultist.h"
#include "trvEntityFoodFarm.h"
#include "trvEntityGoldMine.h"

//   #include <experimental/filesystem>

//  namespace fs = std::experimental::filesystem;


///     Objects of the same type have the same hash in multimap



typedef std::vector <std::unique_ptr <gComponent> > entityConstructorArg;

template <typename T> std::unique_ptr<T> entityInit(entityConstructorArg entityParams) {
  auto returnPtr = std::make_unique <T> (T(entityParams));
  return returnPtr;
}

template <typename T> std::shared_ptr<T> entityCopy(std::unique_ptr<T> entityToCopy) {
  auto entityCopy = std::make_shared<T> (entityToCopy);
  return entityCopy;
}

class trvIOContainerWorld {
 private:
  /*   std::map <std::string, std::function<trvEntity*()>> initObjects = {
      {"MainBuilding",[](){return new trvEntityMainBuilding;}}
  };  */
  //   bool entitiesInitiated = false;

  ///      загрузка порождающих и копирующих конструкторов в map



  int currentGameMode = gCore::MENU_MODE;
  ///  ДОСТУП К ОБЪЕКТУ??????  --  объект хранит свои координаты

  int yMapSize, xMapSize;

 //    player user;
 //    gMap game_map;

 public:

  trvIOContainerWorld() {}
  ~trvIOContainerWorld();

  //      {"MainBuildingInit", []  (entityConstructorArg entityParams) { return new trvEntityMainBuilding(); }},
  std::map <std::string, trvEntity> ancestorObjects;
  std::unordered_multimap <size_t, trvEntity> gameObjects;  //  multimap?


  ///  Structure for runtime determination of objects' properties

  std::map <std::string, std::function< std::unique_ptr <trvEntity> (entityConstructorArg)> > initObjects = {
      {"MainBuildingInit", entityInit<trvEntityMainBuilding>},
      {"MachineGunPointInit", entityInit<trvEntityMachineGunPoint>},
      {"EnemyCultistInit", entityInit<trvEntityEnemyCultist>},
      {"FoodFarmInit", entityInit<trvEntityFoodFarm>},
      {"GoldMineInit", entityInit<trvEntityGoldMine>}
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},,
  };


  ///  Structure for making object copies


//   std::map <std::string, std::function<trvEntity*(trvEntity * )> > copyObjects = {
//      {"MainBuildingCopy", entityCopy<trvEntityMainBuilding>}
//   };

  //    std::map <> =
  /*     std::map <std::string, std::function > initComponents = {
      {"GraphicalComponent", },
      {"HealthComponent", }
  };   */
  //   unsigned int seed_1 = 1, seed_2 = 2, seed_3 = 3;


  //   template <typename entityClass, typename... constructorArgs> void createEntity(constructorArgs... args);
  //   player & get_players();
  void initAncestorObjects();
  void initMap();

  int getCurrentGameMode();
  int getYMapSize() const;
  void setYMapSize(int yMapSize);
  int getXMapSize() const;
  void setXMapSize(int xMapSize);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_WORLD_H
