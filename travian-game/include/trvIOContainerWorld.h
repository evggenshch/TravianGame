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

#include <inttypes.h>


//   #include <experimental/filesystem>

//  namespace fs = std::experimental::filesystem;


///     Objects of the same type have the same hash in multimap


typedef std::vector <std::unique_ptr <gComponent> > entityConstructorArg;
typedef std::unique_ptr <trvEntity> entityCopyArg;

template <typename T> std::unique_ptr<T> entityInit(entityConstructorArg);
//  template <typename T> std::shared_ptr<T> entityCopy(std::string);

template <typename T> std::shared_ptr<T> entityCopy(std::string entityToCopyName, std::map <std::string, std::shared_ptr <trvEntity> > * prototypeObjs) {

  //   std::shared_ptr <gComponent> modelPtr = std::move(  (inputComponents[0]));
  std::shared_ptr <T> derived = std::dynamic_pointer_cast <T> (prototypeObjs->find(entityToCopyName)->second);
  auto entityCopy = std::make_shared <T> (*derived);
//  auto entityCopy = std::make_shared <T> (  std::dynamic_pointer_cast <T>  *(prototypeObjs->find(entityToCopyName)->second));
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
  std::map <std::string, std::shared_ptr <trvEntity> > ancestorObjects;
  std::unordered_multimap <size_t, trvEntity> gameObjects;  //  multimap?

  std::map <std::string, std::function < std::unique_ptr <gComponent> (FILE *)  > > readComponent = {
      {std::string("GraphicMap"), [](FILE * componentFile) {
        int ySize, xSize;
        int curInt;
        wchar_t curChar;
        fscanf(componentFile, "%i %i\n", &ySize, &xSize);
        printf("%i %i\n", ySize, xSize);
        std::vector < std::vector <gTile> > graphicArray(ySize, std::vector <gTile> (xSize, gTile()));
        for(size_t i = 0; i < static_cast<size_t > (ySize); i++) {
          for(size_t j = 0; j < static_cast<size_t > (xSize); j++) {
            fscanf(componentFile, "%lc", &curChar);
            graphicArray[i][j].setSym(curChar);
          }
          fscanf(componentFile, "\n");
        }
        for(size_t i = 0; i < static_cast<size_t > (ySize); i++) {
          for(size_t j = 0; j < static_cast<size_t > (xSize); j++) {
            fscanf(componentFile, "%i", &curInt);
            graphicArray[i][j].setForeColor(curInt);
            fscanf(componentFile, "%i", &curInt);
            graphicArray[i][j].setBackColor(curInt);
          }
        }
        fscanf(componentFile, "\n");
        auto graphicComponent = std::make_unique <trvComponentGraphicalModel> (trvComponentGraphicalModel(graphicArray));
        return graphicComponent;
      }},
      {std::string("Health"), [](FILE * componentFile) {
        int healthValue = 0;
        fscanf(componentFile, "%i\n", &healthValue);
        auto healthComponent = std::make_unique <trvComponentHealth> (trvComponentHealth(healthValue));
        return healthComponent;
      }},
      {std::string("Location"), [](FILE * componentFile) {
        int posY, posX;
        fscanf(componentFile, "%i %i\n", &posY, &posX);
        auto locationComponent = std::make_unique <trvComponentLocation> (trvComponentLocation(posX, posY));
        return locationComponent;
       }
      }
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
  };

  ///  Structure for runtime determination of objects' properties

  std::map <std::string, std::function< std::unique_ptr <trvEntity> (entityConstructorArg)> > initObjects = {
      {"MainBuilding", entityInit<trvEntityMainBuilding>},
      {"MachineGunPoint", entityInit<trvEntityMachineGunPoint>},
      {"CultistEnemy", entityInit<trvEntityEnemyCultist>},
      {"FoodFarm", entityInit<trvEntityFoodFarm>},
      {"GoldMine", entityInit<trvEntityGoldMine>}
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},,
  };


  ///  Structure for making object copies


   std::map <std::string, std::function< std::shared_ptr <trvEntity> ( std::string, std::map <std::string, std::shared_ptr <trvEntity> > * )> > copyObjects = {
      {"MainBuilding", entityCopy<trvEntityMainBuilding>},
      {"MachineGunPoint", entityCopy<trvEntityMachineGunPoint>},
      {"CultistEnemy", entityCopy<trvEntityEnemyCultist>},
      {"FoodFarm", entityCopy<trvEntityFoodFarm>},
      {"GoldMine", entityCopy<trvEntityGoldMine>}
     };

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

template <typename T> std::unique_ptr<T> entityInit(entityConstructorArg entityParams) {
  auto returnPtr = std::make_unique <T> (T(std::move(entityParams)));
  return returnPtr;
}



/*  template <typename T> std::shared_ptr<T> entityCopy(std::unique_ptr<T> entityToCopy) {
  auto entityCopy = std::make_shared<T> (*entityToCopy);
  return entityCopy;
}  */

#endif  //  EVGENIJ_SCHERBAKOV_GAME_WORLD_H
