//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
#define EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
#include "trvIOContainerWorld.h"
#include "include/gGraphics.h"

class trvSystemRendering {
 public:
  static void drawGameObject(trvEntity *);
  static void drawGameMap(trvIOContainerWorld * gameWorld);
  static void update_rt(world * g_w, gRTTimer * game_time);
  static void win_rt_report(world * g_w, g_results_collector <g_core::rt_time > * game_results);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
