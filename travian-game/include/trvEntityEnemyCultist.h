//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVENTITYENEMYCULTIST_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVENTITYENEMYCULTIST_H

#include "trvEntity.h"

class trvEntityEnemyCultist : public trvEntity {
 public:
  explicit trvEntityEnemyCultist(std::vector < std::unique_ptr <gComponent> > input) : trvEntity(std::move(input)) {};
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVENTITYENEMYCULTIST_H
