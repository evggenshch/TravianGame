//
// Created by evggenshch on 10.07.18.
//

#include "include/gTile.h"
#include "include/gEntity.h"

void gTile::setX(int x) { this->x = x; }
void gTile::setY(int y) { this->y = y; }
void gTile::setForeColor(int fore_color) { this->fore_color = fore_color; }
void gTile::setBackColor(int back_color) { this->back_color = back_color; }
void gTile::setSym(char sym) { this->sym = sym; }
void gTile::set_att_g_object(gEntity * att_g_object) { this->att_g_object = att_g_object;}

int gTile::getX() { return x; }
int gTile::getY() { return y; }
int gTile::getForeColor() { return ForeColor; }
int gTile::getBackColor() { return BackColor; }
char gTile::getSym() { return  sym; }
gEntity * gTile::get_att_g_object() { return att_g_object; }

gTile::gTile(int fore_color, int back_color, char sym, gEntity * att_object) {
    this->setForeColor(fore_color);
    this->setBackColor(back_color);
    this->setSym(sym);
    this->set_att_g_object(att_object);
}

gTile::gTile(int x, int y, int fore_color, int back_color, char sym, gEntity * att_object) {
    this->setX(x);
    this->setY(y);
    gTile();
}


