//
// Created by evggenshch on 24.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_POINT_H
#define EVGENIJ_SCHERBAKOV_GAME_G_POINT_H

#include "gLibsEssential.h"
class gPoint {
 private:
  g_core::int_t x, y;
 public:
  gPoint(g_core::int_t, g_core::int_t);
  g_core::int_t get_x();
  g_core::int_t get_y();
  void set_x(g_core::int_t);
  void set_y(g_core::int_t);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_G_POINT_H
