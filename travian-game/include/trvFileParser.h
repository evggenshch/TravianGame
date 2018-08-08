//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H

#include "trvIOContainerWorld.h"
#include "trvComponentHealth.h"
#include "trvComponentGraphicalModel.h"

///  +


namespace trvFileParser {
  std::map <std::string, std::function < std::unique_ptr <gComponent> (FILE *)  > > readComponent = {
      {std::string("GraphicMap"), [](FILE * componentFile) {
        int ySize, xSize, curInt;
        char curChar;
        fscanf(componentFile, "%i %i\n", &ySize, &xSize);
        std::vector < std::vector <gTile> > graphicArray(ySize, std::vector <gTile> (xSize, gTile()));
        for(size_t i = 0; i < static_cast<size_t > (ySize); i++) {
          for(size_t j = 0; j < static_cast<size_t > (xSize); j++) {
            fscanf(componentFile, "%c", &curChar);
            graphicArray[i][j].setSym(curChar);
          }
        }
        for(size_t i = 0; i < static_cast<size_t > (ySize); i++) {
          for(size_t j = 0; j < static_cast<size_t > (xSize); j++) {
            fscanf(componentFile, "%i", &curInt);
            graphicArray[i][j].setForeColor(curInt);
            fscanf(componentFile, "%i", &curInt);
            graphicArray[i][j].setBackColor(curInt);
          }
        }
        auto graphicComponent = std::make_unique <trvComponentGraphicalModel> (trvComponentGraphicalModel(graphicArray));
        return graphicComponent;
      }},
      {std::string("Health"), [](FILE * componentFile) {
        int healthValue;
        fscanf(componentFile, "%i", &healthValue);
        auto healthComponent = std::make_unique <trvComponentHealth> (trvComponentHealth(healthValue));
        return healthComponent;
      }}
//      {"MachineGunPointInit", [] (entityConstructorArg entityParams) {}},
  };

  std::unique_ptr <gComponent> loadComponentFromFile(trvIOContainerWorld *, FILE *);
  std::unique_ptr <trvEntity> loadEntityFromFile (trvIOContainerWorld * , FILE *);
  void loadMapFromFile(trvIOContainerWorld *, FILE *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
