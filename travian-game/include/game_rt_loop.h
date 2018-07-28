//
//  Created by evggenshch on 11.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_GAME_RT_LOOP_H
#define EVGENIJ_SCHERBAKOV_GAME_GAME_RT_LOOP_H
#include <include/g_loop.h>

class game_rt_loop {
 public:
    static void init_rt_loop(g_results_collector <g_core::rt_time > * game_results);
};

#endif  //  EVGENIJ_SCHERBAKOV_GAME_GAME_RT_LOOP_H
