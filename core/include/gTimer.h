//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_TIMER_H
#define EVGENIJ_SCHERBAKOV_GAME_G_TIMER_H

#include "gLibsEssential.h"

template <typename T>
class gTimer {
private:
  T gTime;
public:
  gTimer(T gTime);
  virtual ~gTimer();
  T getGTime() const;
  void setGTime(T gTime);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_G_TIMER_H
