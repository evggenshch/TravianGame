//
// Created by evggenshch on 14.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVUSERINTERFACE_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVUSERINTERFACE_H

#include <ncurses.h>
#include "trvSystemRendering.h"
#include "trvWidget.h"
#include "trvWidgetInfo.h"
#include "trvWidgetMap.h"
#include "trvWidgetStats.h"

class trvIOContainerWorld;

class trvUserInterface {
 private:
    trvWidgetMap mapWidget = trvWidgetMap(70, 140, 0, 0);
    trvWidgetInfo infoWidget = trvWidgetInfo(50, 60, 20, 140);
    trvWidgetStats statsWidget = trvWidgetStats(20, 60, 0, 140);
 public:
    trvUserInterface();
    ~trvUserInterface();
  trvWidgetMap * getMapWidget();
  trvWidgetInfo * getInfoWidget();
  trvWidgetStats * getStatsWidget();
  void drawMapWidget(trvIOContainerWorld *);
  void drawInfoWidget(trvIOContainerWorld *);
  void drawStatsWidget(trvIOContainerWorld *);
  void drawUserInterface(trvIOContainerWorld *);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVUSERINTERFACE_H
