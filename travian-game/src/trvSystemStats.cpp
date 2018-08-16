//
// Created by evggenshch on 19.07.18.
//

#include "../include/trvSystemStats.h"

void trvSystemStats::updateBonus(trvIOContainerWorld * gameWorld  /*, gRTTimer * game_timer,
                             gResultsCollector <g_core::rt_time > * game_results */) {


   gameWorld->setBonusFood(5 * std::distance(gameWorld->gameObjects.equal_range("FoodFarm").first, gameWorld->gameObjects.equal_range("FoodFarm").second));
   gameWorld->setBonusGold(5 * std::distance(gameWorld->gameObjects.equal_range("GoldMine").first, gameWorld->gameObjects.equal_range("GoldMine").second));


/*  if (g_w->get_players().get_got_bonus()) {
    game_timer->change_g_time(g_w->get_map().get_bonus_rt_value());
    g_w->get_players().set_got_bonus(false);
  }    */
}

void trvSystemStats::updateValue(trvIOContainerWorld * gameWorld) {
  gameWorld->changeFoodValue(gameWorld->getBonusFood());
  gameWorld->changeGoldValue(gameWorld->getBonusGold());
}