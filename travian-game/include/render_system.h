//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
#define EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
#include "trvIOContainerWorld.h"
#include "include/gGraphics.h"

class render_system {
 public:
  static void update_tb(world * g_w, g_tb_timer * game_time);
  static void update_rt(world * g_w, g_rt_timer * game_time);
  static void lose_tb_report(world * g_w, g_results_collector <g_core::tb_time > * game_results);
  static void win_tb_report(world * g_w, g_results_collector <g_core::tb_time > * game_results);
  static void win_rt_report(world * g_w, g_results_collector <g_core::rt_time > * game_results);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
