//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_OBJECT_H
#define EVGENIJ_SCHERBAKOV_GAME_G_OBJECT_H

#include "gLibsEssential.h"
#include <functional>

/**
 * g_object represents an abstract class of in-game object (e.g player, coin, wall, etc.)
 * each instance of g_object heritor has specific hash_code allowing to use fabric method
 * for their creation
**/


/**

 TO-DO: g_entity hash constructor

 */

class gEntity {
private:
    size_t hashCode;
public:
    //  virtual gEntity();
    //  virtual ~gEntity();
    size_t getHashCode();
    //  void setHashCode(size_t (*hash_function) <gEntity> = std::hash<gEntity>);
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_OBJECT_H
