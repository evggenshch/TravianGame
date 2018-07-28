//
// Created by evggenshch on 24.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_DIALOG_H
#define EVGENIJ_SCHERBAKOV_GAME_G_DIALOG_H

class gDialog {
 private:
  std::string title;
  g_point top_left, bottom_right;
 public:
  gDialog(g_point, g_point);
  g_point get_top_left();
  g_point get_bottom_right();
  std::string get_title();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_G_DIALOG_H
