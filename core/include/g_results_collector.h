//
// Created by evggenshch on 10.07.18.
//

#ifndef EVGENIJ_SCHERBAKOV_GAME_G_RESULTS_COLLECTOR_H
#define EVGENIJ_SCHERBAKOV_GAME_G_RESULTS_COLLECTOR_H

#include "gLibsEssential.h"

template <typename T> class g_results_collector {
private:
    std::vector < std::pair <T, std::string> > total_score;
    //  std::string cur_player;
    T  cur_score;
public:
    g_results_collector();
    std::vector < std::pair <T, std::string> >  get_sorted_total_score();
    void add_player(std::pair <T, std::string>);
    T get_cur_score();
    size_t get_total_score_size();
    size_t get_name_length_at(size_t);
    std::string get_name_at(size_t);
    T get_score_at(size_t);
    void set_cur_score(T);
    void change_cur_score(T);
};


#endif //EVGENIJ_SCHERBAKOV_GAME_G_RESULTS_COLLECTOR_H
