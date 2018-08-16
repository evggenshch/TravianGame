//
// Created by evggenshch on 30.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMENEMYAI_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMENEMYAI_H

#include <include/gSystem.h>
#include "trvIOContainerWorld.h"
class trvSystemEnemyAI : public gSystem {
 public:
  static void update(trvIOContainerWorld *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMENEMYAI_H
