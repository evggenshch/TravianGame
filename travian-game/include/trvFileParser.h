//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H


#include "trvComponentHealth.h"
#include "trvComponentGraphicalModel.h"
#include "trvEntity.h"
#include "trvIOContainerWorld.h"

class trvIOContainerWorld;

///  +


namespace trvFileParser {


  std::unique_ptr <gComponent> loadComponentFromFile(trvIOContainerWorld *, FILE *);
  std::shared_ptr <trvEntity> loadEntityFromFile (trvIOContainerWorld * , FILE *);
  void loadMapFromFile(trvIOContainerWorld *, FILE *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
