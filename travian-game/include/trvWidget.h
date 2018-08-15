//
// Created by evggenshch on 14.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVMENU_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVMENU_H

#include <vector>
#include <string>
//#include "ncursesw"
#include "ncurses.h"

class trvWidget {
 private:
  WINDOW * widgetWindow;
  int topLeftY, topLeftX, width, height;
  std::string name;
  std::vector < std::string > menuOptions;
 public:
  trvWidget(int, int, int, int);
  trvWidget() {};
  ~trvWidget();
  virtual void drawWidget();
  WINDOW * getWidgetWindow();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVMENU_H
