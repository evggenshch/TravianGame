//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_CELL_H
#define EVGENIJ_SCHERBAKOV_GAME_G_CELL_H

#include "gLibsEssential.h"


/** g_cell represents elementary cell of game field containing  link to the attached game object
 *
 *
 *   +
 */

class gEntity;

class gTile {
private:
    int x, y, ForeColor, BackColor;
    char sym;
    gEntity * att_g_object;
public:
    gTile(int fore_color = 7, int back_color = 0, char sym = '.', gEntity * att_object = nullptr);
    gTile(int, int, int, int, char, gEntity *);
    void setX(int);
    void setY(int);
    void setForeColor (int);
    void setBackColor (int);
    void setSym (char);
    void set_att_g_object(gEntity *);
    int getX();
    int getY();
    int getForeColor();
    int getBackColor();
    char getSym();
    gEntity * get_att_g_object();
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_CELL_H
