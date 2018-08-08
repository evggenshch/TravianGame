//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTHEALTH_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTHEALTH_H

#include <include/gComponent.h>

///       +


class trvComponentHealth : public gComponent {
 private:
  int value;
 public:
  trvComponentHealth(int value);
  virtual ~trvComponentHealth();
  int getValue() const;
  void setValue(int value);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTHEALTH_H
