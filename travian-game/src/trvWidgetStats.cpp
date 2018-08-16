//
// Created by evggenshch on 15.08.18.
//

#include "../include/trvWidgetStats.h"
#include "../include/trvIOContainerWorld.h"

void trvWidgetStats::drawWidget(trvIOContainerWorld * gameWorld) {
  trvWidget::drawWidget();
  wattron(getWidgetWindow(), COLOR_PAIR(7));
  mvwprintw(getWidgetWindow(), 3, 3, "Seconds until next enemy wave: %lf", gameWorld->enemyWaveTimer.getGTime());
  wattroff(getWidgetWindow(), COLOR_PAIR(7));
 // mvwprintw();
 // mvwprintw();
 // mvwprintw();
}