//
// Created by evggenshch on 10.07.18.
//

#include "include/gTile.h"
#include "include/gEntity.h"

void gTile::setX(int x) { this->x = x; }
void gTile::setY(int y) { this->y = y; }
void gTile::setForeColor(int fore_color) { this->foreСolor = fore_color; }
void gTile::setBackColor(int back_color) { this->backСolor = back_color; }
void gTile::setSym(char sym) { this->sym = sym; }

int gTile::getX() { return x; }
int gTile::getY() { return y; }
int gTile::getForeColor() { return ForeColor; }
int gTile::getBackColor() { return BackColor; }
char gTile::getSym() { return  sym; }

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


