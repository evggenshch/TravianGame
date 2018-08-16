//
// Created by evggenshch on 16.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMENTITYCOLLISION_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMENTITYCOLLISION_H

#include "../../core/include/gPoint.h"
#include "../include/trvEntity.h"

namespace trvSystemEntityCollision {
   bool isInside(gPoint, std::shared_ptr <trvEntity>);
   bool isIntersect(std::shared_ptr <trvEntity>, std::shared_ptr <trvEntity>);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVSYSTEMENTITYCOLLISION_H



///   std::distance