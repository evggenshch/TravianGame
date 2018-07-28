//
//  Created by evggenshch on 18.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_WORLD_H
#define EVGENIJ_SCHERBAKOV_GAME_WORLD_H

#include "../include/player.h"
#include "include/gMap.h"

class trvIOContainerWorld {
 private:
  std::unordered_map <size_t, gEntity> gameObjects;  //  multimap?
  int current_game_mode = gCore::MENU_MODE;
  ///  ДОСТУП К ОБЪЕКТУ??????  --  объект хранит свои координаты

  player user;
  gMap game_map;
  int map_count = 1;
 public:
  unsigned int seed_1 = 1, seed_2 = 2, seed_3 = 3;
  trvIOContainerWorld(player input_user,  gMap input_game_map) :  user(input_user), game_map(input_game_map) {
    user = input_user;
    game_map = input_game_map;
  }
  player & get_players();
  gMap & get_map();
  int get_map_count();
  void inc_map_count();
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_WORLD_H
