//
// Created by evggenshch on 10.07.18.
//

#include "include/gTile.h"
#include "include/gEntity.h"

//    void gTile::setX(int x) { this->x = x; }
//    void gTile::setY(int y) { this->y = y; }
void gTile::setColorPair(int colorPair) { this->colorPair = colorPair; }
void gTile::setSym(wchar_t sym) { this->sym = sym; }


int gTile::getColorPair() const { return colorPair; }
wchar_t gTile::getSym() const { return  sym; }

gTile::gTile(int colorPair, wchar_t sym) {
    this->setColorPair(colorPair);
    this->setSym(sym);
}

gTile::gTile(int x, int y, int colorPair, wchar_t sym) {
    this->setX(x);
    this->setY(y);  ///  ?????
    gTile();
}


