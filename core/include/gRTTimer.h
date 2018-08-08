//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H
#define EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H

#include "gTimer.h"

const double_t  EPS = 0.000001;

class gRTTimer : public gTimer <gCore::timer_t > {
public:
  gRTTimer(gCore::timer_t g_time) : gTimer <gCore::timer_t > (g_time) {};
  bool change_g_time(gCore::timer_t);
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_RT_TIMER_H
