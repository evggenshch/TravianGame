//
// Created by evggenshch on 14.08.18.
//

#include "../include/trvPtrEntityMap.h"

trvEntity trvPtrEntityMap::getPtrAt(int y, int x) {
  return *(ptrMap[y][x].lock());
}

void trvPtrEntityMap::setPtrAt(int y, int x, std::shared_ptr<trvEntity> changePtr) {
  ptrMap[y][x] = changePtr;
}