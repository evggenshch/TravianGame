//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_FIELD_PARSER_H
#define EVGENIJ_SCHERBAKOV_GAME_G_FIELD_PARSER_H

#include "gLibsEssential.h"

class g_map_parser {
 public:
  template <typename T> void read_parameter(char *, FILE *, T &);
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_FIELD_PARSER_H
