//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVENTITYFOODFARM_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVENTITYFOODFARM_H

#include <include/gEntity.h>
#include "trvEntity.h"

class trvEntityFoodFarm : public trvEntity {
 public:
  explicit trvEntityFoodFarm(std::vector < std::unique_ptr <gComponent> > input) : trvEntity(std::move(input)) {};
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVENTITYFOODFARM_H
