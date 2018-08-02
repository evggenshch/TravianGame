//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H

#include "trvIOContainerWorld.h"
class trvFileParser {
 public:
  static gEntity * loadEntityFromFile (trvIOContainerWorld * , FILE *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVFILEPARSER_H
