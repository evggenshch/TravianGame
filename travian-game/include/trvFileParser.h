//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H

#include "trvIOContainerWorld.h"
#include "trvComponentHealth.h"
#include "trvComponentGraphicalModel.h"
class trvFileParser {
 public:
  //  static ;

  std::map <std::string, std::function<gComponent*(FILE *)> > readComponent = {
      {"GraphicMap", [](FILE * componentFile) {
        int ySize, xSize, curInt;
        int curChar;
        fscanf(componentFile, "%i %i\n", ySize, xSize);
        std::vector < std::vector <gTile> > graphicArray(ySize, std::vector <gTile> (xSize, gTile()));
        for(size_t i = 0; i < ySize; i++) {
          for(size_t j = 0; j < xSize; j++) {
            fscanf(componentFile, "%c", &curChar);
            graphicArray[i][j].setSym(curChar);
          }
        }
        for(size_t i = 0; i < ySize; i++) {
          for(size_t j = 0; j < xSize; j++) {
            fscanf(componentFile, "%i", &curInt);
            graphicArray[i][j].setForeColor(curInt);
            fscanf(componentFile, "%i", &curInt);
            graphicArray[i][j].setBackColor(curInt);
          }
        }
        trvComponentGraphicalModel * graphicComponent = new trvComponentGraphicalModel(graphicArray);
        return graphicComponent;
      }},
      {"Health", [](FILE * componentFile) {
        int healthValue;
        fscanf(componentFile, "%i", &healthValue);
        trvComponentHealth * healthComponent = new trvComponentHealth(healthValue);
        return healthComponent;
      }}
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
  };

  gComponent * loadComponentFromFile(trvIOContainerWorld *, FILE *);
  trvEntity * loadEntityFromFile (trvIOContainerWorld * , FILE *);
  void loadMapFromFile(trvIOContainerWorld *, FILE *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
