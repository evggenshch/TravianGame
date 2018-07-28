//
// Created by evggenshch on 10.07.18.
//

#include <include/g_rt_timer.h>
#include "include/gGraphics.h"

void gGraphics::startGraphics() {
    initscr();
    noecho();
    // start_color();
}

void gGraphics::drawDialog(gDialog * game_dialog) {
  mvprintw(game_dialog->get_top_left().get_y(), game_dialog->get_top_left().get_x(), "%c", 201);
  mvprintw(game_dialog->get_top_left().get_y(), game_dialog->get_bottom_right().get_x(), "X");
  mvprintw(game_dialog->get_bottom_right().get_y(), game_dialog->get_bottom_right().get_x(), "%c", 188);
  mvprintw(game_dialog->get_bottom_right().get_y(), game_dialog->get_top_left().get_x(), "%c", 200);
  for(size_t i = game_dialog->get_top_left().get_y() + 1; i < game_dialog->get_bottom_right().get_y() - 1; i++) {
    mvprintw(i, game_dialog->get_top_left().get_x(), "%c", 186);
    mvprintw(i, game_dialog->get_bottom_right().get_x(), "%c", 186);
  }
  for(size_t i = game_dialog->get_top_left().get_x() + 1; i < game_dialog->get_bottom_right().get_x(); i++) {
    mvprintw(game_dialog->get_top_left().get_y(), i, "%c", 205);
    mvprintw(game_dialog->get_bottom_right().get_y(), i, "%c", 205);
  }
  mvprintw(game_dialog->get_top_left().get_y(), (game_dialog->get_top_left().get_x() + game_dialog->get_bottom_right().get_x()
               - game_dialog->get_title().length()) / 2, "%s", game_dialog->get_title().c_str());
}



void gGraphics::drawTile(gTile cur_cel) {
    init_pair(1, static_cast<short> (cur_cel.get_fore_color()), static_cast<short> (cur_cel.get_back_color()));
    attron(COLOR_PAIR(1));
    mvprintw(cur_cel.get_y() + 1, cur_cel.get_x() + 1, "%c", cur_cel.get_sym());
    attroff(COLOR_PAIR(1));
}

void gGraphics::drawMap(gMap & cur_map) {
    clear();
    for(size_t i = 0; i <= cur_map.get_size_x() + 1; i++) {
      mvprintw(0, i, "#");
    }
    for(size_t i = 0; i < cur_map.get_size_y(); i++) {
        mvprintw(i + 1, 0, "#");
        for(size_t j = 0; j < cur_map.get_size_x(); j++) {
            draw_g_cell(cur_map.get_g_cell_at(i, j));
        }
        mvprintw(i + 1, cur_map.get_size_x() + 1, "#");
    }
    for(size_t i = 0; i <= cur_map.get_size_x() + 1; i++) {
      mvprintw(cur_map.get_size_y() + 1, i, "#");
    }
}

void gGraphics::print_mes(const char * mes) {
    clear();
    printw("%s\n", mes);
}

void gGraphics::print_int_number(int num, int pos) {
    move(pos, 0);
    printw("%i ", num);
}

void gGraphics::print_stats_rt(g_rt_timer * game_timer, gMap * game_map) {
  move(game_map->get_size_y() + 5, 0);
  printw("Steps remaining:  %lf", game_timer->get_g_time());;
}

int gGraphics::input_key() {
    return getch();
}

/*  void g_ui::input_message(char & str[100]) {
  echo();
  scanw("%s", &str);
  noecho();
}  */

void g_ui::print_score_tb(g_results_collector <g_core::tb_time > * game_results) {
  game_results->get_sorted_total_score();
  mvprintw(1, 0, "YOUR_SCORE:  %i\n", game_results->get_cur_score());
  for(size_t i = 0; i < game_results->get_total_score_size() ; i++) {
    mvprintw(i + 3, 0, "%s", game_results->get_name_at(i).c_str());
    mvprintw(i + 3, static_cast<int> (game_results->get_name_length_at(i)) + 5, "%i", game_results->get_score_at(i));
  }
}

void g_ui::print_score_rt(g_results_collector <g_core::rt_time > * game_results) {
  game_results->get_sorted_total_score();
  mvprintw(1, 0, "YOUR_SCORE: %lf\n", game_results->get_cur_score());
  for(size_t i = 0; i < game_results->get_total_score_size(); i++) {
    mvprintw(i + 3, 0, "%s", game_results->get_name_at(i).c_str());
    mvprintw(i + 3, static_cast<int> (game_results->get_name_length_at(i)) + 5, "%lf", game_results->get_score_at(i));
  }
}

void g_ui::close_g_ui() {
    endwin();
}