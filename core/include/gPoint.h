//
// Created by evggenshch on 24.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_POINT_H
#define EVGENIJ_SCHERBAKOV_GAME_G_POINT_H

#include "gLibsEssential.h"
class gPoint {
 private:
  gCore::int_t x, y;
 public:
  gPoint(gCore::int_t inputX = 0, gCore::int_t inputY = 0);
  gCore::int_t getX() const;
  gCore::int_t getY() const;
  void setX(gCore::int_t);
  void setY(gCore::int_t);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_G_POINT_H
