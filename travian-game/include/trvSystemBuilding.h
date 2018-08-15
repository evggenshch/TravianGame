//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMBUILDING_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMBUILDING_H

#include <include/gSystem.h>
#include "trvIOContainerWorld.h"

class trvSystemBuilding : public gSystem {
 public:
  static void update(trvIOContainerWorld *, int);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMBUILDING_H
