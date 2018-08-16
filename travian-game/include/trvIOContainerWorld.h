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
#include "trvGameCamera.h"
#include "trvUserInterface.h"
#include "../../core/include/gRTTimer.h"

#include "trvPtrEntityMap.h"

#include <inttypes.h>


enum GAME_MODES{
  CAMERA_MODE,
  BUILDING_MODE
};

//   #include <experimental/filesystem>

//  namespace fs = std::experimental::filesystem;


///     Objects of the same type have the same hash in multimap


typedef std::vector <std::unique_ptr <gComponent> > entityConstructorArg;
typedef std::unique_ptr <trvEntity> entityCopyArg;

template <typename T> std::unique_ptr<T> entityInit(entityConstructorArg);
//  template <typename T> std::shared_ptr<T> entityCopy(std::string);
/* void  template <typename T> std::shared_ptr<T>  entityCopy (std::string, std::map <std::string, std::shared_ptr <trvEntity> > *  ); */


    template <typename T> std::shared_ptr<T> entityCopy(std::string entityToCopyName, std::map <std::string, std::shared_ptr <trvEntity> > * prototypeObjs) {

  ///   std::shared_ptr <gComponent> modelPtr = std::move(  (inputComponents[0]));
   std::shared_ptr <T> derived = std::dynamic_pointer_cast <T> (prototypeObjs->find(entityToCopyName)->second);
   auto entityCopy = std::make_shared <T> (*derived);
   //  auto entityCopy = std::make_shared <T> (  std::dynamic_pointer_cast <T>  *(prototypeObjs->find(entityToCopyName)->second));
   //  std::shared_ptr <T> entityCopy;
   return entityCopy;
    }



class trvIOContainerWorld {
 private:

  int yMapSize = 200, xMapSize = 200;
  trvGameCamera trvCamera{0, 0};
  gPoint cursor{0, 0};
  int money = 300, food = 100, steel = 300, glass = 300, concrete = 300, people = 30;



  int gameMode = CAMERA_MODE;

  trvPtrEntityMap entityMap;



 public:

  trvUserInterface gameUI;
  int getGameMode() const;
  void setGameMode(int gameMode);

  int visibleY = 40, visibleX = 40;
  gRTTimer enemyWaveTimer{80.0};

  trvGameCamera * getTrvCamera();
  gPoint * getCursor();
  trvIOContainerWorld() {}
  ~trvIOContainerWorld();

  //      {"MainBuildingInit", []  (entityConstructorArg entityParams) { return new trvEntityMainBuilding(); }},
  std::map <std::string, std::shared_ptr <trvEntity> > ancestorObjects { /* {"Sample", nullptr}  */ };
  std::unordered_multimap <std::string, std::shared_ptr <trvEntity> > gameObjects;

  std::map <std::string, std::function < std::unique_ptr <gComponent> (FILE *)  > > readComponent = {
      {std::string("GraphicMap"), [](FILE * componentFile) {
        int ySize, xSize;
        int curInt;
        wchar_t curChar;
        fscanf(componentFile, "%i %i\n", &ySize, &xSize);
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
            graphicArray[i][j].setColorPair(curInt);
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
  };


  ///  Structure for making object copies


   std::map <std::string, std::function<  std::shared_ptr <trvEntity> (std::string, std::map <std::string, std::shared_ptr <trvEntity> > *)> > copyObjects = {
      {"MainBuilding", entityCopy <trvEntityMainBuilding>},
      {"MachineGunPoint", entityCopy <trvEntityMachineGunPoint>},
      {"CultistEnemy", entityCopy <trvEntityEnemyCultist>},
      {"FoodFarm", entityCopy <trvEntityFoodFarm> },
      {"GoldMine", entityCopy <trvEntityGoldMine> }
      /* {"MainBuilding", []() {
         return 0;
       }}  */
     };

  //   unsigned int seed_1 = 1, seed_2 = 2, seed_3 = 3;


  //   template <typename entityClass, typename... constructorArgs> void createEntity(constructorArgs... args);
  //   player & get_players();
  void initAncestorObjects();
  void initMap();

  int getYMapSize() const;
  void setYMapSize(int yMapSize);
  int getXMapSize() const;
  void setXMapSize(int xMapSize);
};

template <typename T> std::unique_ptr<T> entityInit(entityConstructorArg entityParams) {
  auto returnPtr = std::make_unique <T> (T(std::move(entityParams)));
  return returnPtr;
}


#endif  //  EVGENIJ_SCHERBAKOV_GAME_WORLD_H
