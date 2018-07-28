//
// Created by evggenshch on 10.07.18.
//

#include <include/gGraphics.h>
#include "include/gMap.h"

gMap::gMap(std::ifstream map_fstream) {
  load_map_from_file(map_fstream);
}

gMap::gMap(const char * map_filename) {
  load_map_from_file(map_filename);
}

g_cell gMap::get_g_cell_at(int x, int y) {
    return field[x][y];
}

void gMap::set_g_cell_at(int x, int y, char sym) {
  field[x][y].set_sym(sym);
}

size_t gMap::get_size_x() {
    return size_x;
}

size_t gMap::get_size_y() {
    return size_y;
}

g_core::tb_time gMap::get_bonus_tb_value() {
  return  bonus_tb_value;
}

g_core::tb_time gMap::get_init_tb_time() {
  return init_tb_time;
}

g_core::tb_time gMap::get_tick_per_second() {
  return tick_per_second;
}

g_core::rt_time gMap::get_init_rt_time() {
  return init_rt_time;
}

g_core::rt_time gMap::get_bonus_rt_value() {
  return bonus_rt_value;
}

void gMap::load_map_from_file(std::ifstream & map_file_stream) {
   /** if(!map_file_stream.is_open()) {                      TO-DO check whether file stream is open
    }  **/

    map_file_stream >> size_x;
    map_file_stream >> size_y;
    map_file_stream >> bonus_tb_value;
    map_file_stream >> bonus_rt_value;
    map_file_stream >> init_tb_time;
    map_file_stream >> init_rt_time;
    map_file_stream >> tick_per_second;

    field = std::vector < std::vector <g_cell> > (size_y, std::vector <g_cell> (size_x, g_cell()));

    for(size_t i = 0; i < this->size_x; i++) {
        for(size_t j = 0; j < this->size_y; j++) {
            char temp;
            map_file_stream >> temp;
            field[i][j].set_sym(temp);
            field[i][j].set_fore_color(6);
            field[i][j].set_back_color(1);
            field[i][j].set_y(static_cast<int> (i));
            field[i][j].set_x(static_cast<int> (j));
        }
    }

    map_file_stream.close();
}



void gMap::load_map_from_file(const char *map_filename) {
  std::ifstream input_stream(map_filename);
  gMap::load_map_from_file(input_stream);
}