//
// Created by evggenshch on 17.07.18.
//

#include <vector>
#include "../include/position_component.h"

position_component::position_component(std::vector<g_cell> pos) {
  this->pos = pos;
}

g_cell & position_component::get_posittion_at(size_t i) {
  return pos[i];
}

void position_component::set_position_at(size_t i , g_cell input_cell) {
  pos[i] = input_cell;
}

size_t position_component::get_position_size() {
  return pos.size();
}