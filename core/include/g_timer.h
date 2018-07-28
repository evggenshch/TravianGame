//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_TIMER_H
#define EVGENIJ_SCHERBAKOV_GAME_G_TIMER_H

#include "gLibsEssential.h"

template <typename T>
class g_timer {
private:
  T g_time;
public:
  g_timer(T);
  ~g_timer();
  void set_g_time(T);
  T get_g_time();
 // virtual bool change_g_time(T);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_G_TIMER_H
