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

class gTile : public gPoint {
private:
    int colorPair;
    wchar_t sym;
public:
    gTile(int colorPair = 1, wchar_t sym = '.');
    gTile(int, int, int, wchar_t);
    ~gTile() {};
    void setColorPair (int);
    void setSym (wchar_t);
    int getColorPair() const;
    wchar_t getSym() const;
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_CELL_H
