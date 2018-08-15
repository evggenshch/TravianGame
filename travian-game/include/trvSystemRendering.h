//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
#define EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
#include <include/gSystem.h>
//  #include "trvIOContainerWorld.h"
#include "include/gGraphics.h"
#include "trvGameCamera.h"
#include "trvEntity.h"



///   Rewrite to namespace? (for all game systems)

class trvIOContainerWorld;

class trvSystemRendering : public gSystem {
 public:
  static void drawGameObject(WINDOW *, std::pair <std::string, std::shared_ptr <trvEntity> >, trvGameCamera *);
  static void drawGameMap(WINDOW *,  trvIOContainerWorld * gameWorld);
  static void update(trvIOContainerWorld * gameWorld);
 // static void update_rt(trvIOContainerWorld * gameWorld, gRTTimer * game_time);
  //  static void win_rt_report(trvIOContainerWorld * gameWorld, gResultsCollector < double > * game_results);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_RENDER_SYSTEM_H
