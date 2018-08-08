//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_SPAWN_SYSTEM_H
#define EVGENIJ_SCHERBAKOV_GAME_SPAWN_SYSTEM_H

#include "include/gSystem.h"
#include "include/gTile.h"
#include "trvIOContainerWorld.h"

class trvSystemEnemySpawn : public gSystem  {
 public:
  static void update(trvIOContainerWorld * gameWorld);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_SPAWN_SYSTEM_H
