//
// Created by evggenshch on 10.07.18.
//

#include "../include/g_map_parser.h"

template <typename T> void g_map_parser::read_parameter(char * prefix, FILE * map_file, T &) {
  fscanf(map_file, "%s", prefix);
  ;
}