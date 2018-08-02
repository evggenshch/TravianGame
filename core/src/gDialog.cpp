//
// Created by evggenshch on 24.07.18.
//

#include "include/gDialog.h"

gDialog::gDialog(gPoint inputTopLeft, gPoint inputBottomRight, std::initializer_list <std::string> inputOptions) {
  this->topLeft = inputTopLeft;
  this->bottomRight = inputBottomRight;
  this->options.insert(this->options.end(), inputOptions.begin(), inputOptions.end());
}

gPoint gDialog::getTopLeft() {
  return this->topLeft;
}

gPoint gDialog::getBottomRight() {
  return this->getBottomRight();
}

std::string gDialog::getTitle() {
  return this->title;
}

std::vector <std::string> gDialog::getOptions() {
  return this->options;
}

std::string gDialog::getOptionAt(int i) {
  return options[i];
}
