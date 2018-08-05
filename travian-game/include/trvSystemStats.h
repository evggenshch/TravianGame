//
//  Created by evggenshch on 19.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_STATS_SYSTEM_H
#define EVGENIJ_SCHERBAKOV_GAME_STATS_SYSTEM_H

#include "include/g_results_collector.h"
#include "trvIOContainerWorld.h"
#include "include/gRTTimer.h"

class trvSystemStats {
 public:
  static void update_rt(world *, gRTTimer *, g_results_collector <g_core::rt_time > *);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_STATS_SYSTEM_H
