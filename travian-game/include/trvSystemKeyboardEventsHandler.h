//
// Created by evggenshch on 30.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMKEYBOARDEVENTSHANDLER_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMKEYBOARDEVENTSHANDLER_H

#include <include/gSystem.h>
#include "trvIOContainerWorld.h"

class trvSystemKeyboardEventsHandler : public gSystem {
 public:
  static void update(trvIOContainerWorld * gameWorld, char inputKey);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMKEYBOARDEVENTSHANDLER_H
