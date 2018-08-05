//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H

class trvComponentLocation {
 private:
  int x, y;
 public:
  int getY() const;
  void setY(int y);
  int getX() const;
  void setX(int x);
  trvComponentLocation(int x);
  virtual ~trvComponentLocation();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H
