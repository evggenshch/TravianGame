//
//  Created by evggenshch on 19.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_STATS_SYSTEM_H
#define EVGENIJ_SCHERBAKOV_GAME_STATS_SYSTEM_H

#include <include/gSystem.h>
#include "include/gResultsCollector.h"
#include "trvIOContainerWorld.h"
#include "include/gRTTimer.h"

class trvSystemStats : public gSystem {
 public:
  static void update(trvIOContainerWorld *, gRTTimer *, gResultsCollector < double > *);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_STATS_SYSTEM_H
