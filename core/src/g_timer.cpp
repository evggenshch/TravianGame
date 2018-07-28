//
// Created by evggenshch on 10.07.18.
//

#include "../include/g_timer.h"

template <typename T> g_timer<T>::g_timer(T g_time) {
  set_g_time(g_time);
}

template <typename T> g_timer<T>::~g_timer() {}

template <typename T> void g_timer<T>::set_g_time(T g_time) {
  this->g_time = g_time;
}

template <typename T> T g_timer<T>::get_g_time() {
  return g_time;
}

template class g_timer <g_core::rt_time >;
template class g_timer <g_core::tb_time >;
