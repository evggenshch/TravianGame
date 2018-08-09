//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMACHINEGUNPOINT_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMACHINEGUNPOINT_H

#include <include/gEntity.h>
#include "trvEntity.h"

class trvEntityMachineGunPoint : public trvEntity {
 public:
    trvEntityMachineGunPoint();
    trvEntityMachineGunPoint(std::vector < std::unique_ptr <gComponent> > input) : trvEntity(std::move(input)) {};
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMACHINEGUNPOINT_H
