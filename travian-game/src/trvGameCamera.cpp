//
// Created by evggenshch on 13.08.18.
//

#include "../include/trvGameCamera.h"
trvGameCamera::trvGameCamera(int cameraDX, int cameraDY) : cameraDX(cameraDX), cameraDY(cameraDY) {}
int trvGameCamera::getCameraDX() const {
  return cameraDX;
}
void trvGameCamera::setCameraDX(int cameraDX) {
  trvGameCamera::cameraDX = cameraDX;
}
int trvGameCamera::getCameraDY() const {
  return cameraDY;
}
void trvGameCamera::setCameraDY(int cameraDY) {
  trvGameCamera::cameraDY = cameraDY;
}
void trvGameCamera::changeCameraDX(int dDX) {
  trvGameCamera::cameraDX += dDX;
}
void trvGameCamera::changeCameraDY(int dDY) {
  trvGameCamera::cameraDY += dDY;
}