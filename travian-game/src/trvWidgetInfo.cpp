//
// Created by evggenshch on 15.08.18.
//

#include "../include/trvWidgetInfo.h"
#include "../include/trvIOContainerWorld.h"
#include "../../core/include/gGraphics.h"

void trvWidgetInfo::drawWidget() {
  trvWidget::drawWidget();
  for(int i = 0; i < static_cast<int> (options.size()); i++) {
    if(selectedOption == i) {
      wattron(getWidgetWindow(), COLOR_PAIR(2));
    }
  //  init_pair(4, 0, 7);
 //   wattron(getWidgetWindow(), COLOR_PAIR(4));
    mvwprintw(getWidgetWindow(), 2 + i, 2, "%s", options[i].c_str());
  //  wattroff(getWidgetWindow(), COLOR_PAIR(4));
    if(selectedOption == i) {
      wattroff(getWidgetWindow(), COLOR_PAIR(2));
    }
  };
}

void trvWidgetInfo::changeSelectedOption(int changeValue) {
  int to = selectedOption + changeValue;
  if((to >= 0) && (to < static_cast<int> (options.size()))) {
    selectedOption = to;
  }
}


bool isInside(gPoint checkPoint, std::shared_ptr <trvEntity> rec) {
    return ((checkPoint.getX() >= rec->getPos().getX()) &&
        (checkPoint.getY() >= rec->getPos().getY()) &&
        (checkPoint.getX() <= (rec->getPos().getX()
        + static_cast <int> (rec->getModel().getArray()[0].size()))) &&
        (checkPoint.getY() <= (rec->getPos().getY()
        + static_cast <int> (rec->getModel().getArray().size()))));
}



void trvWidgetInfo::buildSelectedOption(trvIOContainerWorld * gameWorld) {

  bool isPlaceable = true;

  std::shared_ptr <trvEntity> newObj = gameWorld->copyObjects.find(options[selectedOption])->second(options[selectedOption], &gameWorld->ancestorObjects);

//  int toX = newObj->getPos().getX() + static_cast <int> (newObj->getModel().getArray()[0].size());
//  int toY = newObj->getPos().getY() + static_cast <int> (newObj->getModel().getArray().size());

  int newObjBottomY = gameWorld->getCursor()->getY() + static_cast<int> (newObj->getModel().getArray().size() );
  int newObjRightX = gameWorld->getCursor()->getX() + static_cast<int> (newObj->getModel().getArray()[0].size());

  if((newObjRightX < gameWorld->getXMapSize()) || (newObjBottomY < gameWorld->getYMapSize())) {
     std::for_each(gameWorld->gameObjects.begin(), gameWorld->gameObjects.end(), [newObj, gameWorld, newObjBottomY, newObjRightX, &isPlaceable]
         (std::pair <std::string, std::shared_ptr <trvEntity> > curObj) {

        int curObjBottomY = curObj.second->getPos().getY() + static_cast<int> (curObj.second->getModel().getArray().size());
        int curObjRightX = curObj.second->getPos().getX() + static_cast<int> (curObj.second->getModel().getArray()[0].size());

        if(isInside(gPoint(curObj.second->getPos().getX(), curObj.second->getPos().getY()), newObj)
            || isInside(gPoint(curObjRightX, curObj.second->getPos().getY()), newObj)
            || isInside(gPoint(curObj.second->getPos().getX(), curObjBottomY), newObj)
            || isInside(gPoint(curObjRightX, curObjBottomY), newObj)
            || isInside(gPoint(gameWorld->getCursor()->getX(), gameWorld->getCursor()->getY()), curObj.second)
            || isInside(gPoint(newObjRightX, gameWorld->getCursor()->getY()), curObj.second)
            || isInside(gPoint(gameWorld->getCursor()->getX(), newObjBottomY), curObj.second)
            || isInside(gPoint(newObjRightX, newObjBottomY), curObj.second)
            ) {
           isPlaceable = false;
        }
     });
  }
  else {
    isPlaceable = false;
  }

  if(isPlaceable) {
    (*newObj).setPos(trvComponentLocation(gameWorld->getCursor()->getX(),
                                          gameWorld->getCursor()->getY()));

    gameWorld->gameObjects.insert(std::pair<std::string, std::shared_ptr<trvEntity> >
                                      (options[selectedOption], std::move(newObj)));
  }
  else {
   // (*std::get_deleter<trvEntity>(newObj));
    newObj.reset();
  }
}


/*
public boolean isIntersects(Rectangle rectangle) {
  return (isInside(rectangle.leftTop.getX(), rectangle.leftTop.getY()) || isInside(rectangle.rightBottom.getX(), rectangle.rightBottom.getY())
      || isInside(rectangle.leftTop.getX(), rectangle.rightBottom.getY()) || isInside(rectangle.rightBottom.getX(), rectangle.leftTop.getY())
      || rectangle.isInside(leftTop.getX(), leftTop.getY()) || rectangle.isInside(rightBottom.getX(), rightBottom.getY())
      || rectangle.isInside(leftTop.getX(), rightBottom.getY()) || rectangle.isInside(rightBottom.getX(), leftTop.getY()));   */