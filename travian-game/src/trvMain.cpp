//
//  Created by evggenshch on 10.07.18.
//


#include <include/gGraphics.h>
#include <include/gRTTimer.h>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <include/gSystem.h>

#include "../include/trvIOContainerWorld.h"
#include "../include/trvUserInterface.h"
#include "include/gRTTimer.h"
#include "../include/trvSystemRendering.h"
#include "../include/trvSystemCursorMovement.h"
#include "../include/trvSystemEnemySpawn.h"
#include "../include/trvSystemStats.h"
#include "../include/trvSystemKeyboardEventsHandler.h"
#include "../include/trvSystemBuilding.h"

using namespace std::chrono_literals;

int main() {
//    int user_key;

   // while (1) {
      std::setlocale(LC_ALL, "");

      //  en_US.UTF-8"

     gGraphics::initGraphics();

     // wchar_t  a = 'a';

     // mvprintw(1, 1, "%lc", a);
    /*  g_ui::print_mes("Start game (y/n)?");

      switch (user_key) {
        case 'y' : break;
        case 'n' : return 0;
        default: continue;
      }  */
      //   char name_string[100];
      //  gGraphics::print_mes("Enter player name: ");
      //  echo();
      //  scanw("%s", name_string);
      //  noecho();
      //  g_ui::input_message(&name_string);

      //  gGraphics::print_mes("Choose game mode, 'r' for real-time, 't' for turn-based, 'e' for exit ");
      //  user_key = gGraphics::input_key();
      //  printw("%c", user_key);

      //   switch (user_key) {
      //    case 'r' : {
      //        game_rt_results.add_player(std::make_pair(0.0, std::string(name_string)));
      //        game_rt_loop::init_rt_loop(&game_rt_results);
      //      break;
      //    }
      //    case 't' : {
      //      game_tb_results.add_player(std::make_pair(0, std::string(name_string)));
      //      break;
      //     }
      //    default: break;
      //    }
      //    }


  //
//  Created by evggenshch on 11.07.18.
//


      trvIOContainerWorld trvWorld;
  //    trvWorld.initAncestorObjects();
      trvWorld.initMap();
   //   trvSystemRendering::drawGameMap(&trvWorld);
    //  getch();


  /*    void game_rt_loop::init_rt_loop(gResultsCollector <g_core::rt_time > * game_results) {
    player user(std::vector <g_cell> (1, g_cell(0, 0, 7, 0, '@', nullptr)));
    char const * map_init = "Maps/map_0.txt";
    trvIOContainerWorld game_world(user, gMap(map_init));
    game_world.get_map().set_g_cell_at(0, 0, '@');
    gRTTimer game_timer(game_world.get_map().get_init_rt_time());
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
        trvSystemEnemySpawn::update(&game_world);
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
  }  */

/*  player user(std::vector <g_cell> (1, g_cell(0, 0, 7, 0, '@', nullptr)));
  game_world.get_map().set_g_cell_at(0, 0, '@');  */

//  const int FPS=30;


  gRTTimer gameTimer(2000.0);

  std::chrono::high_resolution_clock::time_point previous = std::chrono::high_resolution_clock::now();
  double TICKS = 30.0 / static_cast<double> (30);
  std::chrono::duration <double, std::ratio<1, 30> > lag{0.0};
  char inputKey = 0;
  wtimeout(trvWorld.gameUI.getMapWidget()->getWidgetWindow(), 0);
  wtimeout(trvWorld.gameUI.getInfoWidget()->getWidgetWindow(), 0);
  while (gameTimer.getGTime() >= (1.0 / static_cast<double > (30) * TICKS) + 0.01) {
    if(trvWorld.enemyWaveTimer.getGTime() < (1.0 / static_cast<double > (30) * TICKS) + 0.01) {
      trvSystemEnemySpawn::update(&trvWorld);
      trvWorld.enemyWaveTimer.setGTime(80.0);
    }
    std::chrono::high_resolution_clock::time_point current = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double, std::ratio<1, 30> > elapsed = (current - previous);
    previous = current;
    lag += elapsed;
    inputKey = 0;
  //  inputKey = getch();
 //   trvSystemKeyboardEventsHandler::update(&trvWorld, inputKey);

  /*  int temp = getch();
    if((temp == 'w') || (temp == 'a') || (temp == 's') || (temp == 'd')) {
      input = temp;
    }   */
 /* int temp;
    switch(trvWorld.getCurrentGameMode()) {
      case GAME_MODES::CAMERA_MODE: {
        temp = wgetch(trvWorld.gameUI.getMapWidget()->getWidgetWindow());
        if((temp == 'w') || (temp == 'a') || (temp == 's') || (temp == 'd')) {
          inputKey = temp;
        }
        break;
      }
      case GAME_MODES::BUILDING_MODE: {
        inputKey = wgetch(trvWorld.gameUI.getMapWidget()->getWidgetWindow());
        break;
      }
      default: {
        break;
      }
    }  */
    while ( (lag
        >= std::chrono::duration <double, std::ratio<1, 30> > {1.0 * TICKS}) ) {

      switch(trvWorld.getGameMode()) {
        case GAME_MODES::CAMERA_MODE: {
          trvSystemCursorMovement::update(&trvWorld, inputKey);
          break;
        }
        case GAME_MODES::BUILDING_MODE: {
          trvSystemBuilding::update(&trvWorld, inputKey);
          break;
        }
        default: {
          break;
        }
      }

  //    movement_system::update_rt(&game_world, userKey);
  //    trvSystemEnemySpawn::update(&game_world);
  //    stats_system::update_rt(&game_world, &game_timer, game_results);
      lag -= std::chrono::duration <double, std::ratio<1, 30> > {1.0 * TICKS};
  //    game_results->change_cur_score(1.0 / static_cast<double > (30) * TICKS);
      gameTimer.change_g_time(-1.0 / static_cast<double > (30) * TICKS);
      trvWorld.enemyWaveTimer.change_g_time(-1.0 / static_cast<double> (30) * TICKS);
    }
    trvWorld.gameUI.drawUserInterface(&trvWorld);
 //   trvSystemRendering::drawGameMap(gameUI, &trvWorld);
 //   mvprintw(40, 40, "%lf\n", gameTimer.getGTime());
  }
  wtimeout(trvWorld.gameUI.getMapWidget()->getWidgetWindow(), -1);
  wtimeout(trvWorld.gameUI.getInfoWidget()->getWidgetWindow(), -1);
  //    game_results->change_cur_score(1.0 / static_cast<double > (30)  * TICKS);
  //    render_system::win_rt_report(&game_world, game_results);


    gGraphics::closeGraphics();
}

/*

#include <chrono>
#include <thread>
#include <vector>
#include "include/gRTTimer.h"
#include "../include/game_rt_loop.h"
#include "../include/trvSystemRendering.h"
#include "../include/trvSystemCursorMovement.h"
#include "../include/trvSystemEnemySpawn.h"
#include "../include/trvSystemStats.h"


using namespace std::chrono_literals;

void game_rt_loop::init_rt_loop(gResultsCollector <g_core::rt_time > * game_results) {
  player user(std::vector <g_cell> (1, g_cell(0, 0, 7, 0, '@', nullptr)));
  char const * map_init = "Maps/map_0.txt";
  world game_world(user, gMap(map_init));
  gRTTimer game_timer(game_world.get_map().get_init_rt_time());
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
    trvSystemEnemySpawn::update(&game_world);
    stats_system::update_rt(&game_world, &game_timer, game_results);
  }
  game_results->change_cur_score(1.0 / static_cast<double > (game_world.get_map().get_tick_per_second()));
  trvSystemRendering::win_rt_report(&game_world, game_results);
} */