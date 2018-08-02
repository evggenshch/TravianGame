//
//  Created by evggenshch on 11.07.18.
//

#include <chrono>
#include <thread>
#include <vector>
#include "../../core/include/g_rt_timer.h"
#include "../include/game_rt_loop.h"
#include "../include/trvSystemRendering.h"
#include "../include/trvSystemCursorMovement.h"
#include "../include/spawn_system.h"
#include "../include/trvSystemStats.h"


using namespace std::chrono_literals;

void game_rt_loop::init_rt_loop(g_results_collector <g_core::rt_time > * game_results) {
    player user(std::vector <g_cell> (1, g_cell(0, 0, 7, 0, '@', nullptr)));
    char const * map_init = "Maps/map_0.txt";
    world game_world(user, gMap(map_init));
    g_rt_timer game_timer(game_world.get_map().get_init_rt_time());
    std::chrono::high_resolution_clock::time_point previous = std::chrono::high_resolution_clock.now();
    std::chrono::duration <double, std::chrono::seconds> lag(0.0);       /// * full realtime without delay  //
    while (game_timer.change_g_time(-1.0 / static_cast<double > (game_world.get_map().get_tick_per_second()))) {
      trvSystemRendering::update_rt(&game_world, &game_timer);
      std::chrono::high_resolution_clock::time_point current = std::chrono::high_resolution_clock.now();
      std::chrono::duration <double, std::chrono::seconds> elapsed = std::chrono::duration_cast<std::chrono::seconds>(current - previous);
      previous = current;
      lag += elapsed;
      movement_system::update_rt(&game_world);
      //   std::this_thread::sleep_for(1.0s / static_cast<double > (game_world.get_map().get_tick_per_second()));
      //   game_results->change_cur_score(1.0 / static_cast<double > (game_world.get_map().get_tick_per_second()));
      
      while((lag ) >= ) {

      }
      spawn_system::update(&game_world);
      stats_system::update_rt(&game_world, &game_timer, game_results);
    }
    game_results->change_cur_score(1.0 / static_cast<double > (game_world.get_map().get_tick_per_second()));
    trvSystemRendering::win_rt_report(&game_world, game_results);
}