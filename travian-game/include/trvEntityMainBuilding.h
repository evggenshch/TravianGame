//
// Created by evggenshch on 30.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMAINBUILDING_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMAINBUILDING_H

#include "trvEntity.h"
class trvEntityMainBuilding : public trvEntity {
 public:
  trvEntityMainBuilding();
  trvEntityMainBuilding(std::vector < std::unique_ptr <gComponent> > input) : trvEntity(std::move(input)) {};
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMAINBUILDING_H
