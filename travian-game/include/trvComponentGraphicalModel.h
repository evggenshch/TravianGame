//
// Created by evggenshch on 27.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTGRAPHICALMODEL_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTGRAPHICALMODEL_H


#include <include/gTile.h>
#include <include/gComponent.h>


class trvComponentGraphicalModel : public gComponent {
 private:
    std::vector < std::vector <gTile> > array;
 public:
  const std::vector<std::vector<gTile>> &getArray() const;
  void setArray(const std::vector<std::vector<gTile>> &array);
  trvComponentGraphicalModel(const std::vector<std::vector<gTile>> &array);
  virtual ~trvComponentGraphicalModel();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H
