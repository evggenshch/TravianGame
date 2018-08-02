//
// Created by evggenshch on 27.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H

#include <include/gTile.h>
#include <include/gComponent.h>
class trvComponentGraphicalModel : gComponent {
 private:
    std::vector < std::vector <gTile> > array;
 public:
    trvComponentGraphicalModel(std::vector < std::vector <gTile> > graphicArray) {
      array = graphicArray;
    }
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVCOMPONENTLOCATION_H
