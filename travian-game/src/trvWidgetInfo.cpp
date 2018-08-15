//
// Created by evggenshch on 15.08.18.
//

#include "../include/trvWidgetInfo.h"
#include "../include/trvIOContainerWorld.h"

void trvWidgetInfo::drawWidget() {
  trvWidget::drawWidget();
  for(int i = 0; i < static_cast<int> (options.size()); i++) {
    if(selectedOption == i) {
      init_pair(3, 0, 7);
      wattron(getWidgetWindow(), COLOR_PAIR(3));
    }
  //  init_pair(4, 0, 7);
 //   wattron(getWidgetWindow(), COLOR_PAIR(4));
    mvwprintw(getWidgetWindow(), 2 + i, 2, "%s", options[i].c_str());
  //  wattroff(getWidgetWindow(), COLOR_PAIR(4));
    if(selectedOption == i) {
      wattroff(getWidgetWindow(), COLOR_PAIR(3));
    }
  };
}

void trvWidgetInfo::changeSelectedOption(int changeValue) {
  int to = selectedOption + changeValue;
  if((to >= 0) && (to < static_cast<int> (options.size()))) {
    selectedOption = to;
  }
}

void trvWidgetInfo::buildSelectedOption(trvIOContainerWorld * gameWorld) {

  std::shared_ptr <trvEntity> newObj = gameWorld->copyObjects.find(options[selectedOption])->second(options[selectedOption], &gameWorld->ancestorObjects);

  (*newObj).setPos(trvComponentLocation(gameWorld->getCursor()->getY(), gameWorld->getCursor()->getX()));

  gameWorld->gameObjects.insert(std::pair <std::string, std::shared_ptr <trvEntity> >
                                    (options[selectedOption], std::move(newObj)));
}