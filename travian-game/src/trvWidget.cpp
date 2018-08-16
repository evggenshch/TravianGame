//
// Created by evggenshch on 14.08.18.
//

#include "../include/trvWidget.h"

trvWidget::trvWidget(int height, int width, int topLeftY, int topLeftX) {
  this->height = height;
  this->width = width;
  this->topLeftX = topLeftX;
  this->topLeftY = topLeftY;
  widgetWindow = newwin(height, width, topLeftY, topLeftX);
}

trvWidget::~trvWidget() {
  delwin(widgetWindow);
}

void trvWidget::drawWidget() {
  curs_set(0);
  wborder(widgetWindow, '|', '|', '-', '-', '+', '+', '+', '+');
  mvprintw(topLeftY, topLeftX + (width - name.length()) / 2, "%s", name.c_str());
  wrefresh(widgetWindow);
}

WINDOW * trvWidget::getWidgetWindow() {
  return widgetWindow;
}