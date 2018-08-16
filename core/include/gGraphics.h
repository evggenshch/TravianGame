//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_UI_H
#define EVGENIJ_SCHERBAKOV_GAME_G_UI_H

#include "gMap.h"
#include "gTile.h"
#include "gResultsCollector.h"
#include "gLibsEssential.h"
#include "gTimer.h"
#include "gRTTimer.h"
#include "gDialog.h"

/**
 * Facade for graphics, responsible for user interface
 */

enum TRV_COLORS {
  WHITE_BLACK,
  BLACK_WHITE,
  CYAN_WHITE,
  GREEN_BLACK
};

class gGraphics {
public:
    static void initGraphics();
    static void drawTile(gTile);
    static void drawMap(gMap &);
    static void drawDialog(gDialog *);
    template <typename T> void drawEntity(T * inputEntity);


    static void print_mes(const char *);
    static void print_int_number (int, int);
    static void print_stats_rt(gRTTimer *, gMap *);
    static void print_score_rt(gResultsCollector <gCore::timer_t > * game_results);
    //  static void input_message(char [100] *);
    static void closeGraphics();
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_UI_H
