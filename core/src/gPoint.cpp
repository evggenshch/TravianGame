//
// Created by evggenshch on 24.07.18.
//

#include "include/gPoint.h"

gPoint::gPoint (g_core::int_t input_x, g_core::int_t input_y) {
  set_x(input_x);
  set_y(input_y);
}

g_core::int_t gPoint::get_x() { return this->x; }

g_core::int_t gPoint::get_y() { return this->y; }

void gPoint::set_x(g_core::int_t input_x) { this->x = input_x; }

void gPoint::set_y(g_core::int_t input_y) { this->y = input_y; }
