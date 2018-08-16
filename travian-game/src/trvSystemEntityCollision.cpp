//
// Created by evggenshch on 16.08.18.
//

//  #include <include/gPoint.h>
#include "../include/trvSystemEntityCollision.h"


bool trvSystemEntityCollision::isInside(gPoint checkPoint, std::shared_ptr <trvEntity> rec) {
    return ((checkPoint.getX() >= rec->getPos().getX()) &&
        (checkPoint.getY() >= rec->getPos().getY()) &&
        (checkPoint.getX() <= (rec->getPos().getX()
        + static_cast <int> (rec->getModel().getArray()[0].size()))) &&
        (checkPoint.getY() <= (rec->getPos().getY()
        + static_cast <int> (rec->getModel().getArray().size()))));
}

bool trvSystemEntityCollision::isIntersect(std::shared_ptr <trvEntity> obj1, std::shared_ptr <trvEntity> obj2) {

  int Obj1BottomY = obj1->getPos().getY() + static_cast<int> (obj1->getModel().getArray().size() );
  int Obj1RightX = obj1->getPos().getX() + static_cast<int> (obj1->getModel().getArray()[0].size());

  int Obj2BottomY = obj2->getPos().getY() + static_cast<int> (obj2->getModel().getArray().size());
  int Obj2RightX = obj2->getPos().getX() + static_cast<int> (obj2->getModel().getArray()[0].size());

  return (isInside(gPoint(obj2->getPos().getX(), obj2->getPos().getY()), obj1)
      || isInside(gPoint(Obj2RightX, obj2->getPos().getY()), obj1)
      || isInside(gPoint(obj2->getPos().getX(), Obj2BottomY), obj1)
      || isInside(gPoint(Obj2RightX, Obj2BottomY), obj1)
      || isInside(gPoint(obj1->getPos().getX(), obj1->getPos().getY()), obj2)
      || isInside(gPoint(Obj1RightX, obj1->getPos().getY()), obj2)
      || isInside(gPoint(obj1->getPos().getX(), Obj1BottomY), obj2)
      || isInside(gPoint(Obj1RightX, Obj1BottomY), obj2));
}