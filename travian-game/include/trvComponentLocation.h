//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H

#include <initializer_list>
#include <include/gComponent.h>

class trvComponentLocation : public gComponent {
 private:
  int x, y;
 public:
  int getY() const;
  void setY(int y);
  int getX() const;
  void setX(int x);
  trvComponentLocation(int x, int y);
  ~trvComponentLocation();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H
