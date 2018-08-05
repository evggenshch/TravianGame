//
// Created by evggenshch on 02.08.18.
//

#include "../include/trvComponentHealth.h"
int trvComponentHealth::getValue() const {
  return value;
}
void trvComponentHealth::setValue(int value) {
  trvComponentHealth::value = value;
}
trvComponentHealth::trvComponentHealth(int value) : value(value) {}
trvComponentHealth::~trvComponentHealth() {

}
