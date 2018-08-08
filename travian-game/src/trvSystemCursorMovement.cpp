//
// Created by evggenshch on 17.07.18.
//

#include "../include/trvSystemCursorMovement.h"

/*    void trvSystemCursorMovement::update(trvIOContainerWorld * g_w) {
  timeout(0);
  int user_key, dy, dx;
  user_key = ;
  switch (user_key) {
    case 'w': {
      dy = -1;
      dx = 0;
      break;
    }
    case 's': {
      dy = 1;
      dx = 0;
      break;
    }
    case 'a': {
      dy = 0;
      dx = -1;
      break;
    }
    case 'd': {
      dy = 0;
      dx = 1;
      break;
    }
    case 27: exit(0);
    default: break;
  }
  for (size_t i = 0; i < g_w->get_players().get_location().get_position_size(); i++) {
    int x_mov = g_w->get_players().get_location().get_posittion_at(i).get_x() + dx,
        y_mov = g_w->get_players().get_location().get_posittion_at(i).get_y() + dy;
    if ((x_mov >= 0) && (y_mov >= 0) && (x_mov < static_cast<int> (g_w->get_map().get_size_x()))
        && (y_mov < static_cast<int> (g_w->get_map().get_size_y()))) {
      if ((g_w->get_map().get_g_cell_at(y_mov, x_mov).get_sym() != '#')) {
        switch (g_w->get_map().get_g_cell_at(y_mov, x_mov).get_sym()) {
          case '$' : {
            g_w->get_players().set_got_bonus(true);
            break;
          };
          case '>' : {
            g_w->get_players().set_got_exit(true);
            break;
          };
          default : break;
        }

        g_w->get_map().set_g_cell_at(g_w->get_players().get_location().get_posittion_at(i).get_y(),
                                    g_w->get_players().get_location().get_posittion_at(i).get_x(),
                                    '.');
        g_w->get_players().get_location().get_posittion_at(i).set_x(
            g_w->get_players().get_location().get_posittion_at(i).get_x() + dx);
        g_w->get_players().get_location().get_posittion_at(i).set_y(
            g_w->get_players().get_location().get_posittion_at(i).get_y() + dy);
        g_w->get_map().set_g_cell_at(y_mov, x_mov, '@');
      }
    }
  }
  timeout(-1);
}    */
