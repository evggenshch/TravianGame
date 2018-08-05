//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvEntity.h"
const trvComponentLocation &trvEntity::getPos() const {
  return pos;
}
void trvEntity::setPos(const trvComponentLocation &pos) {
  trvEntity::pos = pos;
}
const trvComponentGraphicalModel &trvEntity::getModel() const {
  return model;
}
void trvEntity::setModel(const trvComponentGraphicalModel &model) {
  trvEntity::model = model;
}
trvEntity::trvEntity(const trvComponentLocation &pos, const trvComponentGraphicalModel &model)
    : pos(pos), model(model) {}
trvEntity::~trvEntity() {

}