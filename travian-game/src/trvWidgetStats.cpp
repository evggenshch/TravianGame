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
  mvwprintw(getWidgetWindow(), 5, 3, "Gold: %i", gameWorld->getGoldValue());
  mvwprintw(getWidgetWindow(), 6, 3, "Food: %i", gameWorld->getFoodValue());
  wattron(getWidgetWindow(), COLOR_PAIR(4));
  mvwprintw(getWidgetWindow(), 5, 15, "        +%i per 15 seconds", gameWorld->getBonusGold());
  mvwprintw(getWidgetWindow(), 6, 15, "        +%i per 15 seconds", gameWorld->getBonusFood());
  wattroff(getWidgetWindow(), COLOR_PAIR(4));
 // mvwprintw();
 // mvwprintw();
 // mvwprintw();
}