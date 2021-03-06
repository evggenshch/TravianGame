//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_BASIC_LIBS_H
#define EVGENIJ_SCHERBAKOV_GAME_BASIC_LIBS_H



#include <vector>
#include <functional>
#include <ctime>
//#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cinttypes>
#include <ctime>
#include <random>
#include <ratio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <map>
#include <thread>
#include <ncurses.h>
#include <unordered_map>
//#include <backward/hash_map>
#include <string>
#include <algorithm>
#include <typeinfo>

namespace gCore {
  typedef double timer_t;
  typedef int int_t;
  typedef double float_t;

  const size_t HASH_BASE = 4294967291;
  enum EVENT_CODES {KEY_PRESSED};
  enum GAME_MODES {MENU_MODE, CAMERA_MODE, CONSTRUCTION_MODE, BUILDING_MODE};
}

// typedef int int_t;
//typedef double g_time_t;

/*
const size_t MAP_SIZE_X = 200;
const size_t MAP_SIZE_Y = 200;
const int RT_TICKS_NUM = 30; */

/*
const char* MAP_FILE_PREFIX = "map_";
const char* CONF_FILE_PREFIX = "map_conf_"; */

#endif //EVGENIJ_SCHERBAKOV_GAME_BASIC_LIBS_H