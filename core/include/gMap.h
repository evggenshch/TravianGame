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
    std::vector < std::vector <g_cell> > field;
    g_core::tb_time bonus_tb_value, tick_per_second, init_tb_time;
    g_core::rt_time  bonus_rt_value, init_rt_time;
public:
    gMap(std::ifstream);
    gMap(const char *);
    g_cell get_g_cell_at(int, int);
    void set_g_cell_at(int, int, char);
    size_t get_size_x();
    size_t get_size_y();
    g_core::tb_time get_bonus_tb_value();
    g_core::tb_time get_tick_per_second();
    g_core::tb_time get_init_tb_time();
    g_core::rt_time get_bonus_rt_value();
    g_core::rt_time get_init_rt_time();
    void load_map_from_file(std::ifstream &);
    void load_map_from_file(const char * map_filename);
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_MAP_H
