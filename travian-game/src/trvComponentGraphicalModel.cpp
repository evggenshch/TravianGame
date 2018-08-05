//
// Created by evggenshch on 27.07.18.
//

#include "../include/trvComponentGraphicalModel.h"
const std::vector<std::vector<gTile>> &trvComponentGraphicalModel::getArray() const {
  return array;
}
void trvComponentGraphicalModel::setArray(const std::vector<std::vector<gTile>> &array) {
  trvComponentGraphicalModel::array = array;
}
trvComponentGraphicalModel::trvComponentGraphicalModel(const std::vector<std::vector<gTile>> &array) : array(array) {}
trvComponentGraphicalModel::~trvComponentGraphicalModel() {
}
