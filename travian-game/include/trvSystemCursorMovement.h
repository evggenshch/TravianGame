//
//  Created by evggenshch on 17.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_MOVEMENT_SYSTEM_H
#define EVGENIJ_SCHERBAKOV_GAME_MOVEMENT_SYSTEM_H

#include "include/gSystem.h"
#include "include/gLibsEssential.h"
#include "include/gGraphics.h"
#include "trvIOContainerWorld.h"

class trvSystemCursorMovement  {
 public:
  static void update(world * g_w);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_MOVEMENT_SYSTEM_H
