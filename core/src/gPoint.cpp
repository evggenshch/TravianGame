//
// Created by evggenshch on 24.07.18.
//

#include "include/gPoint.h"

gPoint::gPoint (gCore::int_t input_x, gCore::int_t input_y) {
  setX(input_x);
  setY(input_y);
}

gCore::int_t gPoint::getX() const { return this->x; }

gCore::int_t gPoint::getY() const { return this->y; }

void gPoint::setX(gCore::int_t input_x) { this->x = input_x; }

void gPoint::setY(gCore::int_t input_y) { this->y = input_y; }
