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
  trvComponentLocation pos = trvComponentLocation(0, 0);
  trvComponentGraphicalModel model;
 public:
  trvEntity(const trvComponentLocation &pos, const trvComponentGraphicalModel &model);
  virtual trvEntity(std::vector <std::unique_ptr <gComponent>>);
  virtual ~trvEntity();
  const trvComponentLocation &getPos() const;
  const trvComponentGraphicalModel &getModel() const;
  void setPos(const trvComponentLocation &pos);
  void setModel(const trvComponentGraphicalModel &model);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVGAMEENTITY_H
