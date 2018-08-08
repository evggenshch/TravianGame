//
// Created by evggenshch on 10.07.18.
//

#include <include/gGraphics.h>
#include "include/gMap.h"

gMap::gMap(std::ifstream map_fstream) {
 //  load_map_from_file(map_fstream);
}

gMap::gMap(const char * map_filename) {
 //  load_map_from_file(map_filename);
}

gTile gMap::get_g_cell_at(int x, int y) {
    return field[x][y];
}

void gMap::set_g_cell_at(int x, int y, char sym) {
  field[x][y].setSym(sym);
}

size_t gMap::get_size_x() {
    return size_x;
}

size_t gMap::get_size_y() {
    return size_y;
}

gCore::timer_t gMap::get_init_rt_time() {
  return init_rt_time;
}

gCore::timer_t gMap::get_bonus_rt_value() {
  return bonus_rt_value;
}
