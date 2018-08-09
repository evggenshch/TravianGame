//
// Created by evggenshch on 26.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVBUILDING_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVBUILDING_H

#include "trvComponentGraphicalModel.h"
#include "trvEntity.h"

class trvEntityBuilding : public trvEntity {
 private:

 public:
  explicit trvEntityBuilding(std::vector < std::unique_ptr <gComponent> > input) : trvEntity(std::move(input)) {};
  ~trvEntityBuilding();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVBUILDING_H
