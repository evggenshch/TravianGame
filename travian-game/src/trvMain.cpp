//
//  Created by evggenshch on 10.07.18.
//


#include <include/gGraphics.h>
#include <include/g_rt_timer.h>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include "../include/game_rt_loop.h"
#include "../include/trvIOContainerWorld.h"

int main() {
    int user_key;
    g_results_collector <g_core::tb_time > game_tb_results;
    g_results_collector <g_core::rt_time > game_rt_results;

    while (1) {


      g_ui::init_g_ui();
    /*  g_ui::print_mes("Start game (y/n)?");

      switch (user_key) {
        case 'y' : break;
        case 'n' : return 0;
        default: continue;
      }  */
      char name_string[100];
      g_ui::print_mes("Enter player name: ");
      echo();
      scanw("%s", name_string);
      noecho();
      //  g_ui::input_message(&name_string);

      g_ui::print_mes("Choose game mode, 'r' for real-time, 't' for turn-based, 'e' for exit ");
      user_key = g_ui::input_key();
      printw("%c", user_key);

      switch (user_key) {
        case 'r' : {
            game_rt_results.add_player(std::make_pair(0.0, std::string(name_string)));
            game_rt_loop::init_rt_loop(&game_rt_results);
            break;
        }
        case 't' : {
            game_tb_results.add_player(std::make_pair(0, std::string(name_string)));
            break;
        }
        default: break;
      }
    }


  //
//  Created by evggenshch on 11.07.18.
//


#include "../../core/include/g_rt_timer.h"
#include "../include/game_rt_loop.h"
#include "../include/render_system.h"
#include "../include/trvSystemCursorMovement.h"
#include "../include/spawn_system.h"
#include "../include/stats_system.h"


  using namespace std::chrono_literals;

  void game_rt_loop::init_rt_loop(g_results_collector <g_core::rt_time > * game_results) {
    player user(std::vector <g_cell> (1, g_cell(0, 0, 7, 0, '@', nullptr)));
    char const * map_init = "Maps/map_0.txt";
    trvIOContainerWorld game_world(user, gMap(map_init));
    game_world.get_map().set_g_cell_at(0, 0, '@');
    g_rt_timer game_timer(game_world.get_map().get_init_rt_time());
    std::chrono::high_resolution_clock::time_point previous = std::chrono::high_resolution_clock::now();
    double TICKS = 30.0 / static_cast<double> (game_world.get_map().get_tick_per_second());
    //    Hack for changing FPS
    std::chrono::duration <double, std::ratio<1, 30> > lag{0.0};
    int user_key = 0;
    timeout(0);
    while (game_timer.get_g_time() >= (1.0 / static_cast<double > (30) * TICKS) + 0.01) {
      std::chrono::high_resolution_clock::time_point current = std::chrono::high_resolution_clock::now();
      std::chrono::duration <double, std::ratio<1, 30> > elapsed = (current - previous);
      previous = current;
      lag += elapsed;
      int temp = getch();
      if ((temp == 'w') || (temp == 'a') || (temp == 's') || (temp == 'd')) {
        user_key = temp;
      }
      while ( (lag
          >= std::chrono::duration <double, std::ratio<1, 30> > {1.0 * TICKS}) ) {
        movement_system::update_rt(&game_world, user_key);
        spawn_system::update(&game_world);
        stats_system::update_rt(&game_world, &game_timer, game_results);
        lag -= std::chrono::duration <double, std::ratio<1, 30> > {1.0 * TICKS};
        game_results->change_cur_score(1.0 / static_cast<double > (30) * TICKS);
        game_timer.change_g_time(-1.0 / static_cast<double > (30) * TICKS);
      }
      render_system::update_rt(&game_world, &game_timer);
    }
    timeout(-1);
    game_results->change_cur_score(1.0 / static_cast<double > (30)  * TICKS);
    render_system::win_rt_report(&game_world, game_results);
  }
    //  g_ui::close_g_ui();
}