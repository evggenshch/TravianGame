//
// Created by evggenshch on 15.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETSTATS_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETSTATS_H

#include "trvWidget.h"
class trvWidgetStats : public  trvWidget {
 public:
  trvWidgetStats() {};
  trvWidgetStats(int height, int width, int topLeftY, int topLeftX) : trvWidget(height, width, topLeftY, topLeftX) {};
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETSTATS_H
