//
// Created by evggenshch on 30.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMATERIAL_H
#define EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMATERIAL_H

///     +

class trvComponentMaterial {
 private:
    int color;
 public:
  trvComponentMaterial(int color);
  ~trvComponentMaterial();
  int getColor() const;
  void setColor(int color);
};

#endif //EVGENIJ_SCHERBAKOV_GAME_TRVENTITYMATERIAL_H
