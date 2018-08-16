//
// Created by evggenshch on 15.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETSTATS_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETSTATS_H

#include "trvWidget.h"

class trvIOContainerWorld;

class trvWidgetStats : public  trvWidget {
 public:
  trvWidgetStats() {};
  trvWidgetStats(int height, int width, int topLeftY, int topLeftX) : trvWidget(height, width, topLeftY, topLeftX) {};
  void drawWidget(trvIOContainerWorld *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETSTATS_H
