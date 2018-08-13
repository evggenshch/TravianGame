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
  for(size_t i = 0; i < this->array.size(); i++) {
    for(size_t j = 0; j < this->array[i].size(); j++) {
      array[i][j].~gTile();
    }
    this->array[i].clear();
  }
  this->array.clear();
  std::vector< std::vector <gTile> >().swap(array);
}
