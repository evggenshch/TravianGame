//
//  Created by evggenshch on 11.07.18.
//

#include "../include/player.h"
#include "include/gTile.h"


position_component & player::get_location() {
  return location;
}

bool player::get_got_bonus() { return got_bonus; }

bool player::get_got_exit() { return got_exit; }

bool player::get_got_step() { return got_step; }

void player::set_got_bonus(bool got_bonus) { this->got_bonus = got_bonus; }

void player::set_got_exit(bool got_exit) { this->got_exit = got_exit; }

void player::set_got_step(bool got_step) { this->got_step = got_step; }