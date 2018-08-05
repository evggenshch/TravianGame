//
// Created by evggenshch on 10.07.18.
//

#include "include/gRTTimer.h"
#include <cmath>

bool gRTTimer::change_g_time(g_core::rt_time change_time) {
  g_core::rt_time cur_g_time = get_g_time();
  cur_g_time += change_time;
  if(cur_g_time > EPS) {
    set_g_time(cur_g_time);
    return true;
  }
  return false;
}