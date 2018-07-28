//
// Created by evggenshch on 10.07.18.
//

#include "../include/g_results_collector.h"

template <typename T> g_results_collector<T>::g_results_collector() {
}

template <typename T> std::vector < std::pair <T, std::string> > g_results_collector<T>::get_sorted_total_score() {
    std::stable_sort(total_score.begin(), total_score.end());
    std::reverse(total_score.begin(), total_score.end());
    return total_score;
}

template <typename T>  void g_results_collector<T>::add_player(std::pair <T, std::string> new_player) {
    cur_score = new_player.first;
    total_score.push_back(new_player);
}

template <typename T> T g_results_collector<T>::get_cur_score() {
  return cur_score;
}

template <typename T> void g_results_collector<T>::set_cur_score(T input_cur_score) {
  this->cur_score = input_cur_score;
  this->total_score[total_score.size() - 1].first = input_cur_score;
}

template <typename T> void g_results_collector<T>::change_cur_score(T input_change) {
  this->cur_score += input_change;
  this->total_score[total_score.size() - 1].first += input_change;
}

template <typename T> size_t g_results_collector<T>::get_total_score_size() {
  return this->total_score.size();
}

template <typename T> size_t g_results_collector<T>::get_name_length_at(size_t i) {
  return this->total_score[i].second.length();
}

template <typename T> std::string g_results_collector<T>::get_name_at(size_t i) {
  return this->total_score[i].second;
}

template <typename T> T g_results_collector<T>::get_score_at(size_t i) {
  return this->total_score[i].first;
}

template class g_results_collector <g_core::rt_time >;
template class g_results_collector <g_core::tb_time >;