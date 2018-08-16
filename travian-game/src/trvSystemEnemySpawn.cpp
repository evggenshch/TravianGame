//
// Created by evggenshch on 18.07.18.
//

#include <include/gGraphics.h>
#include "../include/trvSystemEnemySpawn.h"

void trvSystemEnemySpawn::update(trvIOContainerWorld * gameWorld) {    /*** random_device does not function for some reason  **/

  for(int i = 1; i <= 5; i++) {
    std::shared_ptr <trvEntity> newObj = gameWorld->copyObjects.find("CultistEnemy")->second("CultistEnemy", &gameWorld->ancestorObjects);

    (*newObj).setPos(trvComponentLocation(i * 5,
                                          5));

    gameWorld->gameObjects.insert(std::pair<std::string, std::shared_ptr<trvEntity> >
                                      ("CultistEnemy", std::move(newObj)));
  }
  // bool flag_success = false;
  // std::random_device rd;
  // std::mt19937 mt(rand());
  //  std::uniform_int_distribution <int> dist_x(0, g_w.get_map().get_size_x());
  //  std::uniform_int_distribution <int> dist_y(0, g_w.get_map().get_size_y());
  // for(size_t i = 0; i < 10; i++) {
  // for(s) {
  //  int cur_x = dist_x(mt);   && ((rand_r(&seed_3) % 20) == 0)
  //  int cur_y = dist_y(mt);

  //  int cur_x = rand_r(&g_w->seed_1) % g_w->get_map().get_size_x();
  //  int cur_y = rand_r(&g_w->seed_2) % g_w->get_map().get_size_y();

  /*    if ((g_w->get_map().get_g_cell_at(cur_y, cur_x).get_sym() == '.') && ((rand_r(&g_w->seed_3) % 8) == 0)) {
      g_w->get_map().set_g_cell_at(cur_y, cur_x, '$');
  }   */
}