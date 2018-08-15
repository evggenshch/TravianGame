//
// Created by evggenshch on 15.08.18.
//


#include "../include/trvWidgetMap.h"
#include "../include/trvIOContainerWorld.h"


void trvWidgetMap::drawWidget(trvIOContainerWorld * gameWorld) {
  trvWidget::drawWidget();
  trvSystemRendering::drawGameMap(getWidgetWindow(), gameWorld);
  mvwprintw(getWidgetWindow(), 40, 40, "%i", gameWorld->getGameMode());
}