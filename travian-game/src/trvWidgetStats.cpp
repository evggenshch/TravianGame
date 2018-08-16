//
// Created by evggenshch on 15.08.18.
//

#include "../include/trvWidgetStats.h"
#include "../include/trvIOContainerWorld.h"

void trvWidgetStats::drawWidget(trvIOContainerWorld * gameWorld) {
  trvWidget::drawWidget();
  wattron(getWidgetWindow(), COLOR_PAIR(8));
  mvwprintw(getWidgetWindow(), 3, 3, "Seconds until next enemy wave: %lf", gameWorld->enemyWaveTimer.getGTime());
  wattroff(getWidgetWindow(), COLOR_PAIR(8));
  wattron(getWidgetWindow(), COLOR_PAIR(5));
  mvwprintw(getWidgetWindow(), 5, 3, "Gold: %i", gameWorld->getGoldValue());
  wattroff(getWidgetWindow(), COLOR_PAIR(5));
  wattron(getWidgetWindow(), COLOR_PAIR(10));
  mvwprintw(getWidgetWindow(), 6, 3, "Food: %i", gameWorld->getFoodValue());
  wattroff(getWidgetWindow(), COLOR_PAIR(10));
  wattron(getWidgetWindow(), COLOR_PAIR(1));
  mvwprintw(getWidgetWindow(), 7, 3, "Steel: %i", gameWorld->getSteelValue());
  wattroff(getWidgetWindow(), COLOR_PAIR(1));
  wattron(getWidgetWindow(), COLOR_PAIR(9));
  mvwprintw(getWidgetWindow(), 8, 3, "Glass: %i", gameWorld->getGlassValue());
  wattroff(getWidgetWindow(), COLOR_PAIR(9));
  wattron(getWidgetWindow(), COLOR_PAIR(7));
  mvwprintw(getWidgetWindow(), 9, 3, "Concrete: %i", gameWorld->getConcreteValue());
  wattroff(getWidgetWindow(), COLOR_PAIR(7));
  wattron(getWidgetWindow(), COLOR_PAIR(11));
  mvwprintw(getWidgetWindow(), 10, 3, "People: %i", gameWorld->getPeopleValue());
  wattroff(getWidgetWindow(), COLOR_PAIR(11));


  wattron(getWidgetWindow(), COLOR_PAIR(4));
  mvwprintw(getWidgetWindow(), 5, 15, "        +%i per 15 seconds", gameWorld->getBonusGold());
  mvwprintw(getWidgetWindow(), 6, 15, "        +%i per 15 seconds", gameWorld->getBonusFood());
  mvwprintw(getWidgetWindow(), 7, 15, "        +%i per 15 seconds", gameWorld->getBonusSteel());
  mvwprintw(getWidgetWindow(), 8, 15, "        +%i per 15 seconds", gameWorld->getBonusGlass());
  mvwprintw(getWidgetWindow(), 9, 15, "        +%i per 15 seconds", gameWorld->getBonusConcrete());
  wattroff(getWidgetWindow(), COLOR_PAIR(4));
 // mvwprintw();
 // mvwprintw();
 // mvwprintw();
}