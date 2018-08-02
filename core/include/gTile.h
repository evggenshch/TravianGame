//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_CELL_H
#define EVGENIJ_SCHERBAKOV_GAME_G_CELL_H

#include "gLibsEssential.h"
#include "gPoint.h"

/** g_cell represents elementary cell of game field containing  link to the attached game object
 *
 *
 *   +
 */

class gEntity;

class gTile : gPoint {
private:
    int foreColor, backColor;
    char sym;
public:
    gTile(int fore_color = 7, int back_color = 0, char sym = '.');
    gTile(int, int, int, int, char);
    void setX(int);
    void setY(int);
    void setForeColor (int);
    void setBackColor (int);
    void setSym (char);
    int getX();
    int getY();
    int getForeColor();
    int getBackColor();
    char getSym();
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_CELL_H
