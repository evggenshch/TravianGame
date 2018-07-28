//
//  Created by evggenshch on 17.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_POSITION_COMPONENT_H
#define EVGENIJ_SCHERBAKOV_GAME_POSITION_COMPONENT_H

#include <vector>
#include "include/gLibsEssential.h"
#include "include/gTile.h"

class position_component {
 private:
    std::vector <g_cell> pos;
 public:
    explicit position_component(std::vector <g_cell>);
    g_cell & get_posittion_at(size_t);
    void set_position_at(size_t, g_cell);
    size_t get_position_size();
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_POSITION_COMPONENT_H
