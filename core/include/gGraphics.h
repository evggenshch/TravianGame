//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_UI_H
#define EVGENIJ_SCHERBAKOV_GAME_G_UI_H

#include "gMap.h"
#include "gTile.h"
#include "g_results_collector.h"
#include "gLibsEssential.h"
#include "g_timer.h"
#include "g_rt_timer.h"
#include "gDialog.h"

/**
 * Facade for graphics, responsible for user interface
 */


class gGraphics {
public:
    static void startGraphics();
    static void drawTile(gTile);
    static void drawMap(gMap &);
    static void drawDialog(gDialog *);
    static template <typename T> void drawEntity(T * inputEntity);


    static void print_mes(const char *);
    static void print_int_number (int, int);
    static void print_stats_rt(g_rt_timer *, gMap *);
    static void print_score_tb(g_results_collector <gCore::tb_time > * game_results);
    static void print_score_rt(g_results_collector <gCore::rt_time > * game_results);
    //  static void input_message(char [100] *);
    static void close_g_ui();
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_UI_H
