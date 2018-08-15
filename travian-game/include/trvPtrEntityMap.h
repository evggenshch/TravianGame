//
// Created by evggenshch on 14.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVPTRENTITYMAP_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVPTRENTITYMAP_H

#include "trvEntity.h"
class trvPtrEntityMap {
 private:
  std::vector < std::vector < std::weak_ptr <trvEntity> > > ptrMap;
 public:
  trvEntity getPtrAt(int, int);
  void setPtrAt(int, int, std::shared_ptr <trvEntity>);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVPTRENTITYMAP_H
