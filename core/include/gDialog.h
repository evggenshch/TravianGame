//
// Created by evggenshch on 24.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_DIALOG_H
#define EVGENIJ_SCHERBAKOV_GAME_G_DIALOG_H

#include "gPoint.h"

class gDialog {
 private:
  std::string title;
  std::vector <std::string> options;
  gPoint topLeft, bottomRight;
 public:
  gDialog(gPoint inputTopLeft, gPoint inputBottomRight, std::initializer_list <std::string>);
  gPoint getTopLeft();
  gPoint getBottomRight();
  std::string getTitle();
  std::vector <std::string> getOptions();
  std::string getOptionAt(int i);
  virtual ~gDialog();
};

#endif //EVGENIJ_SCHERBAKOV_GAME_G_DIALOG_H
