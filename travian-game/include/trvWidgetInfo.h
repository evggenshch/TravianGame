//
// Created by evggenshch on 15.08.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETINFO_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETINFO_H

#include "trvWidget.h"


class trvIOContainerWorld;

class trvWidgetInfo : public trvWidget {
 private:
   int selectedOption = 0;
   std::vector < std::string > options = { "MainBuilding", "MachineGunPoint", "FoodFarm", "GoldMine" };
 public:
   trvWidgetInfo() {};
   trvWidgetInfo(int height, int width, int topLeftY, int topLeftX) : trvWidget(height, width, topLeftY, topLeftX) {};
   void drawWidget();
   void buildSelectedOption(trvIOContainerWorld *);
   void changeSelectedOption(int);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVWIDGETINFO_H
