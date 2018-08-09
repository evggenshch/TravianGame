//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_MAP_H
#define EVGENIJ_SCHERBAKOV_GAME_G_MAP_H

#include "gLibsEssential.h"
#include "gEntity.h"
#include "gTile.h"

/**
 * The only authorized source for map constructor's data are files
 * map file includes its configuration
 */

 /**
  * Load
  *
  * X_SIZE:
  * Y_SIZE:
  * BONUS_VALUE:
  * TICKS_PER_SECOND:
  * INIT_RT_TIME:
  * INIT_TB_TIME:
  */

class gMap {
private:
    size_t size_x, size_y;
    std::vector < std::vector <gTile> > field;
    gCore::timer_t  bonus_rt_value, init_rt_time;
public:
    gMap(std::ifstream);
    gMap(const char *);
    gTile get_g_cell_at(int, int);
    void set_g_cell_at(int, int, wchar_t);
    size_t get_size_x();
    size_t get_size_y();
    gCore::timer_t get_bonus_rt_value();
    gCore::timer_t get_init_rt_time();
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_MAP_H
