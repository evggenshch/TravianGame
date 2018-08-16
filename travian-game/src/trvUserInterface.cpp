//
// Created by evggenshch on 14.08.18.
//

#include "../include/trvUserInterface.h"
#include "../include/trvIOContainerWorld.h"

trvUserInterface::trvUserInterface() {
}

trvUserInterface::~trvUserInterface() {
 //mapWidget.~trvWidget();
 //  ;
 // delwin(statsWindow);
}
trvWidgetMap * trvUserInterface::getMapWidget()  {
  return &mapWidget;
}
trvWidgetInfo * trvUserInterface::getInfoWidget() {
  return &infoWidget;
}
trvWidgetStats * trvUserInterface::getStatsWidget()  {
  return &statsWidget;
}
void trvUserInterface::drawUserInterface(trvIOContainerWorld * gameWorld) {
  mapWidget.drawWidget(gameWorld);
  infoWidget.drawWidget();
  statsWidget.drawWidget(gameWorld);
}