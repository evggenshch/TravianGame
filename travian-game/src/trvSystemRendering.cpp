//
// Created by evggenshch on 18.07.18.
//

#include "../include/trvSystemRendering.h"

void trvSystemRendering::drawGameObject(std::pair <std::string, std::shared_ptr <trvEntity> > inputNode) {
  trvEntity gameObject = *inputNode.second;
  for(size_t i = 0; i < gameObject.getModel().getArray().size(); i++) {
    for(size_t j = 0; j < gameObject.getModel().getArray()[i].size(); j++) {
      init_pair(1, gameObject.getModel().getArray()[i][j].getForeColor(), gameObject.getModel().getArray()[i][j].getBackColor());
      attron(COLOR_PAIR(1));
      mvprintw(gameObject.getPos().getY(), gameObject.getPos().getX(), "%lc", gameObject.getModel().getArray()[i][j].getSym());
      attroff(COLOR_PAIR(1));
    }
  }
}

void trvSystemRendering::drawGameMap(trvIOContainerWorld *gameWorld) {
  for(size_t i = 0; i < static_cast<size_t > (gameWorld->getYMapSize()); i++) {
    for(size_t j = 0; j < static_cast<size_t > (gameWorld->getXMapSize()); j++) {
      mvprintw(i, j, ".");
    }
  }
  std::for_each(gameWorld->gameObjects.begin(), gameWorld->gameObjects.end(), drawGameObject);
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