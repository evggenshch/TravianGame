//
// Created by evggenshch on 10.07.18.
//

#include "include/gTimer.h"

template <typename T> gTimer<T>::gTimer(T g_time) {
  set_g_time(g_time);
}

template <typename T> gTimer<T>::~gTimer() {}

template <typename T> void gTimer<T>::set_g_time(T g_time) {
  this->g_time = g_time;
}

template <typename T> T gTimer<T>::get_g_time() {
  return g_time;
}

template class gTimer <gСore::rt_time >;
