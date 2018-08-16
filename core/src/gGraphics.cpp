//
// Created by evggenshch on 10.07.18.
//

#include <include/gRTTimer.h>
#include "include/gGraphics.h"



void gGraphics::initGraphics() {  //   +
    initscr();
    noecho();
    start_color();
    init_pair(1, 7, 0);     // WHITE-BLACK
    init_pair(2, 0, 7);     //  BLACK-WHITE
    init_pair(3, 4, 7);         //  BLUE-WHITE
    init_pair(4, 2, 0);     //  GREEN-BLACK
    init_pair(5, 3, 0);     //  YELLOW-BLACK
    init_pair(6, 3, 7);     //  YELLOW-WHITE
    init_pair(7, 1, 0);     //  RED-BLACK
    init_pair(8, 1, 7);     // RED-WHITE
    init_pair(9, 6, 0);      //  CYAN-BLACK
    init_pair(10, 5, 0);    // MAGENTA-BLACK
  //  init_pair(8, );     //
  //  init_pair(9, );     //
  //  init_pair(10, );     //
}

void gGraphics::drawDialog(gDialog * gameDialog) {    //   +
  mvprintw(gameDialog->getTopLeft().getY(), gameDialog->getTopLeft().getX(), "%c", 201);
  mvprintw(gameDialog->getTopLeft().getY(), gameDialog->getBottomRight().getX(), "X");
  mvprintw(gameDialog->getBottomRight().getY(), gameDialog->getBottomRight().getX(), "%c", 188);
  mvprintw(gameDialog->getBottomRight().getY(), gameDialog->getTopLeft().getX(), "%c", 200);
  for(size_t i = gameDialog->getTopLeft().getY() + 1; i < static_cast<size_t > (gameDialog->getBottomRight().getY() - 1); i++) {
    mvprintw(i, gameDialog->getTopLeft().getX(), "%c", 186);
    mvprintw(i, gameDialog->getBottomRight().getX(), "%c", 186);
  }
  for(size_t i = gameDialog->getTopLeft().getX() + 1; i < static_cast<size_t > (gameDialog->getBottomRight().getX()); i++) {
    mvprintw(gameDialog->getTopLeft().getY(), i, "%c", 205);
    mvprintw(gameDialog->getBottomRight().getY(), i, "%c", 205);
  }
  mvprintw(gameDialog->getTopLeft().getY(), (gameDialog->getTopLeft().getX() + gameDialog->getBottomRight().getX()
               - gameDialog->getTitle().length()) / 2, "%s", gameDialog->getTitle().c_str());
  for(size_t i = 0; i < gameDialog->getOptions().size(); i++) {
    mvprintw(i + (gameDialog->getTopLeft().getX() + gameDialog->getBottomRight().getX() - gameDialog->getOptions().size()) / 2 + 1,
             (gameDialog->getTopLeft().getX() + gameDialog->getBottomRight().getX()
                 - gameDialog->getOptionAt(i).length()) / 2,
             "%s", gameDialog->getOptionAt(i).c_str());
  }
}

template <typename T> void gGraphics::drawEntity(T * inputEntity) {
  for(size_t i = 0; i < inputEntity->pos.size(); i++) {

  }
}


/*  void gGraphics::drawTile(gTile cur_cel) {
    init_pair(1, static_cast<short> (cur_cel.getForeColor()), static_cast<short> (cur_cel.getBackColor()));
    attron(COLOR_PAIR(1));
    mvprintw(cur_cel.getY() + 1, cur_cel.getX() + 1, "%c", cur_cel.getSym());
    attroff(COLOR_PAIR(1));
}   */

/*    void gGraphics::drawMap(gMap & cur_map) {
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
}    */

void gGraphics::print_mes(const char * mes) {
    clear();
    printw("%s\n", mes);
}

void gGraphics::print_int_number(int num, int pos) {
    move(pos, 0);
    printw("%i ", num);
}

void gGraphics::print_stats_rt(gRTTimer * game_timer, gMap * game_map) {
  move(game_map->get_size_y() + 5, 0);
  printw("Steps remaining:  %lf", game_timer->getGTime());;
}



/*  void g_ui::input_message(char & str[100]) {
  echo();
  scanw("%s", &str);
  noecho();
}  */


void gGraphics::print_score_rt(gResultsCollector <gCore::timer_t > * game_results) {
  game_results->get_sorted_total_score();
  mvprintw(1, 0, "YOUR_SCORE: %lf\n", game_results->get_cur_score());
  for(size_t i = 0; i < game_results->get_total_score_size(); i++) {
    mvprintw(i + 3, 0, "%s", game_results->get_name_at(i).c_str());
    mvprintw(i + 3, static_cast<int> (game_results->get_name_length_at(i)) + 5, "%lf", game_results->get_score_at(i));
  }
}

void gGraphics::closeGraphics() {
    endwin();
}