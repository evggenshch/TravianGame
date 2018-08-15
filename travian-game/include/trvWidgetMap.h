//
// Created by evggenshch on 15.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETMAP_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETMAP_H

#include "trvSystemRendering.h"
#include "trvWidget.h"


class trvIOContainerWorld;

class trvWidgetMap : public trvWidget {
 public:
  trvWidgetMap() {};
  trvWidgetMap(int height, int width, int topLeftY, int topLeftX) : trvWidget(height, width, topLeftY, topLeftX) {};
  void drawWidget(trvIOContainerWorld *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETMAP_H
