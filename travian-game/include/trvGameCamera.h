//
// Created by evggenshch on 13.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVGAMECAMERA_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVGAMECAMERA_H

class trvGameCamera {
 private:
  int cameraDX, cameraDY;
 public:
  trvGameCamera(int cameraDX, int cameraDY);
  int getCameraDX() const;
  void setCameraDX(int cameraDX);
  int getCameraDY() const;
  void setCameraDY(int cameraDY);
  void changeCameraDX(int dDX);
  void changeCameraDY(int dDY);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVGAMECAMERA_H
