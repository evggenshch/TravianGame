//
// Created by evggenshch on 18.07.18.
//

#include "../include/render_system.h"

void render_system::update_tb(world * g_w, g_tb_timer * game_timer) {
  g_ui::draw_g_map(g_w->get_map());
  g_ui::print_stats_tb(game_timer, &g_w->get_map());
}

void render_system::update_rt(world * g_w, g_rt_timer * game_timer) {
  g_ui::draw_g_map(g_w->get_map());
  g_ui::print_stats_rt(game_timer, &g_w->get_map());
}

void render_system::lose_tb_report(world * g_w, g_results_collector <g_core::tb_time > * game_results) {
  clear();
  g_ui::print_mes("YOU LOSE!");
  g_ui::print_score_tb(game_results);
  g_ui::input_key();
}

void render_system::win_tb_report(world * g_w, g_results_collector <g_core::tb_time > * game_results) {
  clear();
  g_ui::print_mes("YOU WON!");
  g_ui::print_score_tb(game_results);
  g_ui::input_key();
}

void render_system::win_rt_report(world * g_w, g_results_collector <g_core::rt_time > * game_results) {
  clear();
  g_ui::print_mes("YOU WON!");
  g_ui::print_score_rt(game_results);
  g_ui::input_key();
}