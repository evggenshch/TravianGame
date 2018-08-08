//
// Created by evggenshch on 30.07.18.
//

#include "../include/trvComponentMaterial.h"
trvComponentMaterial::trvComponentMaterial(int color) : color(color) {}
trvComponentMaterial::~trvComponentMaterial() {
}
int trvComponentMaterial::getColor() const {
  return color;
}
void trvComponentMaterial::setColor(int color) {
  trvComponentMaterial::color = color;
}
