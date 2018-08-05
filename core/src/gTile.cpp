//
// Created by evggenshch on 10.07.18.
//

#include "include/gTile.h"
#include "include/gEntity.h"

//    void gTile::setX(int x) { this->x = x; }
//    void gTile::setY(int y) { this->y = y; }
void gTile::setForeColor(int foreColor) { this->foreColor = foreColor; }
void gTile::setBackColor(int backColor) { this->backColor = backColor; }
void gTile::setSym(char sym) { this->sym = sym; }

int gTile::getX() const { return x; }
int gTile::getY() const { return y; }
int gTile::getForeColor() const { return foreColor; }
int gTile::getBackColor() const { return backColor; }
char gTile::getSym() const { return  sym; }

gTile::gTile(int fore_color, int back_color, char sym) {
    this->setForeColor(fore_color);
    this->setBackColor(back_color);
    this->setSym(sym);
}

gTile::gTile(int x, int y, int fore_color, int back_color, char sym) {
    this->setX(x);
    this->setY(y);
    gTile();
}


