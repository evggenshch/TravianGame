//
// Created by evggenshch on 18.07.18.
//

#include "../include/trvSystemRendering.h"
#include <ncursesw/cursesw.h>
#include "../include/trvIOContainerWorld.h"


void trvSystemRendering::drawGameObject(WINDOW * mapWindow, std::pair <std::string, std::shared_ptr <trvEntity> > inputNode, trvGameCamera * trvCamera) {


  trvEntity gameObject = *inputNode.second;
    for (size_t i = 0; i < gameObject.getModel().getArray().size(); i++) {
      for (size_t j = 0; j < gameObject.getModel().getArray()[i].size(); j++) {
             int toY = gameObject.getPos().getY() + gameObject.getModel().getArray()[i][j].getY() + i;
             int toX = gameObject.getPos().getX() + gameObject.getModel().getArray()[i][j].getX() + j;
            if((toY - trvCamera->getCameraDY() >= 0) && (toY - trvCamera->getCameraDY() <= 30)
                && (toX - trvCamera->getCameraDX() >= 0) && (toX - trvCamera->getCameraDX() <= 30)) {
              init_pair(i * gameObject.getModel().getArray()[i].size() + j,
                        gameObject.getModel().getArray()[i][j].getForeColor(),
                        gameObject.getModel().getArray()[i][j].getBackColor());
              wattron(mapWindow, COLOR_PAIR(i * gameObject.getModel().getArray()[i].size() + j));
            //  mvaddc
            //  mvaddwstr(gameObject.getPos().getY() + i, gameObject.getPos().getX() + j, gameObject.getModel().getArray()[i][j].getSym());
              mvwprintw(mapWindow, toY - trvCamera->getCameraDY() + 1,
                       toX - trvCamera->getCameraDX() + 1,
                       "%lc",
                       gameObject.getModel().getArray()[i][j].getSym());
              wattroff(mapWindow, COLOR_PAIR(i * gameObject.getModel().getArray()[i].size() + j));
            }
      }
    }
}

void trvSystemRendering::drawGameMap(WINDOW * mapWindow, trvIOContainerWorld *gameWorld) {
  for(size_t i = 0; i < 30  /* static_cast<size_t > (gameWorld->getYMapSize()) */; i++) {
    for(size_t j = 0; j < 30 /* static_cast<size_t > (gameWorld->getXMapSize()) */; j++) {
      mvwprintw(mapWindow, i + 1, j + 1, ".");
    }
  }
  std::for_each(gameWorld->gameObjects.begin(), gameWorld->gameObjects.end(), [gameWorld, mapWindow](std::pair <std::string, std::shared_ptr <trvEntity> > inputNode)
                { drawGameObject(mapWindow, inputNode, gameWorld->getTrvCamera()); }
  );
  init_pair(2, 5, 0);
  wattron(mapWindow, COLOR_PAIR(2));
  mvwprintw(mapWindow, gameWorld->getCursor()->getY() + 1, gameWorld->getCursor()->getX() + 1, "X");
  wattroff(mapWindow, COLOR_PAIR(2));
}

/*    void trvSystemRendering::update_rt(trvIOContainerWorld * gameWorld, gRTTimer * game_timer) {
  drawGameMap(gameWorld);
  g_ui::print_stats_rt(game_timer, &g_w->get_map());
}    */

/*    void trvSystemRendering::win_rt_report(world * g_w, gResultsCollector <g_core::rt_time > * game_results) {
  clear();
  g_ui::print_mes("YOU WON!");
  g_ui::print_score_rt(game_results);
  g_ui::input_key();
}   */