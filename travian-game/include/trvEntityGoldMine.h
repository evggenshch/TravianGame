//
// Created by evggenshch on 02.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVENTITYGOLDMINE_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVENTITYGOLDMINE_H

#include <include/gEntity.h>
#include "trvEntity.h"

class trvEntityGoldMine : public trvEntity {
 public:
    trvEntityGoldMine();
    trvEntityGoldMine(std::vector < std::shared_ptr <gComponent> >);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVENTITYGOLDMINE_H
