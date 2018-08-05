//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H
#define EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H

#include "gTimer.h"

const double_t  EPS = 0.000001;

class gRTTimer : public gTimer <g_core::rt_time > {
public:
  gRTTimer(g_core::rt_time g_time) : gTimer <g_core::rt_time> (g_time) {};
  bool change_g_time(g_core::rt_time);
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H
