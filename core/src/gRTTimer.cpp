//
// Created by evggenshch on 10.07.18.
//

#include "include/gRTTimer.h"
#include <cmath>

bool gRTTimer::change_g_time(gCore::timer_t changeTime) {
  gCore::timer_t cur_g_time = getGTime();
  cur_g_time += changeTime;
  if(cur_g_time > EPS) {
    setGTime(cur_g_time);
    return true;
  }
  return false;
}