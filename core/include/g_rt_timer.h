//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H
#define EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H

#include "g_timer.h"

const double_t  EPS = 0.000001;

class g_rt_timer : public g_timer <g_core::rt_time > {
public:
  g_rt_timer(g_core::rt_time g_time) : g_timer <g_core::rt_time> (g_time) {};
  bool change_g_time(g_core::rt_time);
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H
