//
// Created by evggenshch on 18.07.18.
//

#include "../include/trvSystemRendering.h"
#include <ncursesw/cursesw.h>
#include "../include/trvIOContainerWorld.h"
#include "../../core/include/gGraphics.h"


void trvSystemRendering::drawGameObject(WINDOW * mapWindow, std::pair <std::string, std::shared_ptr <trvEntity> > inputNode, trvGameCamera * trvCamera) {


  trvEntity gameObject = *inputNode.second;
    for (size_t i = 0; i < gameObject.getModel().getArray().size(); i++) {
      for (size_t j = 0; j < gameObject.getModel().getArray()[i].size(); j++) {
             int toY = gameObject.getPos().getY() + /* gameObject.getModel().getArray()[i][j].getY() */ + i;
             int toX = gameObject.getPos().getX() /* + gameObject.getModel().getArray()[i][j].getX() */ + j;
            if(((toY - trvCamera->getCameraDY() + 1) >= 1) && ((toY - trvCamera->getCameraDY() + 1) <= 40)
                && ((toX - trvCamera->getCameraDX() + 1) >= 1) && ((toX - trvCamera->getCameraDX() + 1) <= 40)) {
            /*  init_pair(i * gameObject.getModel().getArray()[i].size() + j,
                        gameObject.getModel().getArray()[i][j].getForeColor(),
                        gameObject.getModel().getArray()[i][j].getBackColor());  */
              wattron(mapWindow, COLOR_PAIR(gameObject.getModel().getArray()[i][j].getColorPair()));
            //  mvaddc
            //  mvaddwstr(gameObject.getPos().getY() + i, gameObject.getPos().getX() + j, gameObject.getModel().getArray()[i][j].getSym());
              mvwprintw(mapWindow, toY - trvCamera->getCameraDY() + 1,
                       toX - trvCamera->getCameraDX() + 1,
                       "%lc",
                       gameObject.getModel().getArray()[i][j].getSym());
              wattroff(mapWindow, COLOR_PAIR(gameObject.getModel().getArray()[i][j].getColorPair()));
            }
      }
    }
}

void trvSystemRendering::drawGameMap(WINDOW * mapWindow, trvIOContainerWorld *gameWorld) {
  for(size_t i = std::max(-gameWorld->getTrvCamera()->getCameraDY(), 1); i <=
      static_cast<size_t > (std::min(gameWorld->getYMapSize() - gameWorld->getTrvCamera()->getCameraDY(), gameWorld->visibleY)) /* static_cast<size_t > (gameWorld->getYMapSize()) */; i++) {
    for(size_t j = std::max(-gameWorld->getTrvCamera()->getCameraDX(), 1); j <=
        static_cast<size_t >  (std::min(gameWorld->getXMapSize() - gameWorld->getTrvCamera()->getCameraDX(), gameWorld->visibleX)) /* static_cast<size_t > (gameWorld->getXMapSize()) */; j++) {
      mvwprintw(mapWindow, i, j, ".");
    }
  }
  std::for_each(gameWorld->gameObjects.begin(), gameWorld->gameObjects.end(), [gameWorld, mapWindow](std::pair <std::string, std::shared_ptr <trvEntity> > inputNode)
                { drawGameObject(mapWindow, inputNode, gameWorld->getTrvCamera()); }
  );
  wattron(mapWindow, COLOR_PAIR(10));
  mvwprintw(mapWindow, gameWorld->getCursor()->getY() - gameWorld->getTrvCamera()->getCameraDY() + 1,
            gameWorld->getCursor()->getX() - gameWorld->getTrvCamera()->getCameraDX() + 1, "X");
  wattroff(mapWindow, COLOR_PAIR(10));
}

///   In cursor variable - actual position on the game field
/// In camera - neccessary shift of objects and cursor


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