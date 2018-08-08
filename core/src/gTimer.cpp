//
// Created by evggenshch on 10.07.18.
//

#include "include/gTimer.h"


template <typename T> gTimer<T>::~gTimer() {}
template<typename T>
T gTimer<T>::getGTime() const {
  return gTime;
}
template<typename T>
void gTimer<T>::setGTime(T gTime) {
  this->gTime = gTime;
}
template<typename T>
gTimer<T>::gTimer(T gTime):gTime(gTime) {}


template class gTimer <gCore::timer_t >;
