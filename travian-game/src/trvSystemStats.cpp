//
// Created by evggenshch on 19.07.18.
//

#include "../include/trvSystemStats.h"

void trvSystemStats::update(world * g_w, g_rt_timer * game_timer,
                             g_results_collector <g_core::rt_time > * game_results) {
  if (g_w->get_players().get_got_bonus()) {
    game_timer->change_g_time(g_w->get_map().get_bonus_rt_value());
    g_w->get_players().set_got_bonus(false);
  }
}