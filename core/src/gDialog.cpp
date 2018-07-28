//
// Created by evggenshch on 24.07.18.
//

#include "include/gDialog.h"

gDialog::gDialog(g_point, g_point) {
}

g_point gDialog::get_top_left() {
  return top_left;
}

g_point gDialog::get_bottom_right() {
  return bottom_right;
}

std::string gDialog::get_title() {
  return title;
}