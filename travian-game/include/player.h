//
//  Created by evggenshch on 11.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_PLAYER_H
#define EVGENIJ_SCHERBAKOV_GAME_PLAYER_H

#include <vector>
#include "include/gMap.h"
#include "include/gEntity.h"
#include "../include/position_component.h"

class player : public gEntity {
 private:
  bool got_bonus = false;
  bool got_exit = false;
  bool got_step = false;
  position_component location;
 public:
  explicit player(std::vector <g_cell> pos) : location(pos) {}
  position_component & get_location();
  bool get_got_bonus();
  bool get_got_exit();
  bool get_got_step();
  void set_got_bonus(bool input_got_bonus);
  void set_got_exit(bool input_got_exit);
  void set_got_step(bool input_got_step);
};


#endif  //  EVGENIJ_SCHERBAKOV_GAME_PLAYER_H
