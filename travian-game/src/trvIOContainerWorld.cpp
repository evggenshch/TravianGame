//
// Created by evggenshch on 18.07.18.
//

#include "../include/trvIOContainerWorld.h"

player & world::get_players() {
  return user;
}

gMap & world::get_map() {
  return game_map;
}

int world::get_map_count() {
  return map_count;
}

void world::inc_map_count() {
  ++map_count;
}