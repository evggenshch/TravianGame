//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvComponentLocation.h"
trvComponentLocation::trvComponentLocation(int x, int y) : x(x), y(y) {}
int trvComponentLocation::getX() const {
  return x;
}
void trvComponentLocation::setX(int x) {
  trvComponentLocation::x = x;
}
int trvComponentLocation::getY() const {
  return y;
}
void trvComponentLocation::setY(int y) {
  trvComponentLocation::y = y;
}
trvComponentLocation::~trvComponentLocation() {

}
