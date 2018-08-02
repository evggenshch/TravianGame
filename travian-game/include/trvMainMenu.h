//
// Created by evggenshch on 26.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVMAINMENU_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVMAINMENU_H

#include <include/gDialog.h>
#include <include/gPoint.h>

class trvMainMenu : public gDialog {
 public:
  trvMainMenu(gPoint inputTopLeft, gPoint inputBottomRight, std::initializer_list <std::string> inputOptions) : gDialog(inputTopLeft, inputBottomRight,
  inputOptions) {}
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVMAINMENU_H
