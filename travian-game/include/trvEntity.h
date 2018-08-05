//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVGAMEENTITY_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVGAMEENTITY_H

#include <include/gEntity.h>
#include "trvComponentLocation.h"
#include "trvComponentGraphicalModel.h"
#include "trvComponentHealth.h"

class trvEntity : public gEntity {
 private:
  trvComponentLocation pos;
  trvComponentGraphicalModel model;
 public:
  const trvComponentLocation &getPos() const;
  void setPos(const trvComponentLocation &pos);
  const trvComponentGraphicalModel &getModel() const;
  void setModel(const trvComponentGraphicalModel &model);
  trvEntity(const trvComponentLocation &pos, const trvComponentGraphicalModel &model);
  virtual ~trvEntity();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVGAMEENTITY_H
