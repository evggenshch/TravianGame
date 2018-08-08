//
// Created by evggenshch on 10.07.18.
//

#include "include/gResultsCollector.h"

template <typename T> gResultsCollector<T>::gResultsCollector() {
}

template <typename T> std::vector < std::pair <T, std::string> > gResultsCollector<T>::get_sorted_total_score() {
    std::stable_sort(total_score.begin(), total_score.end());
    std::reverse(total_score.begin(), total_score.end());
    return total_score;
}

template <typename T>  void gResultsCollector<T>::add_player(std::pair <T, std::string> new_player) {
    cur_score = new_player.first;
    total_score.push_back(new_player);
}

template <typename T> T gResultsCollector<T>::get_cur_score() {
  return cur_score;
}

template <typename T> void gResultsCollector<T>::set_cur_score(T input_cur_score) {
  this->cur_score = input_cur_score;
  this->total_score[total_score.size() - 1].first = input_cur_score;
}

template <typename T> void gResultsCollector<T>::change_cur_score(T input_change) {
  this->cur_score += input_change;
  this->total_score[total_score.size() - 1].first += input_change;
}

template <typename T> size_t gResultsCollector<T>::get_total_score_size() {
  return this->total_score.size();
}

template <typename T> size_t gResultsCollector<T>::get_name_length_at(size_t i) {
  return this->total_score[i].second.length();
}

template <typename T> std::string gResultsCollector<T>::get_name_at(size_t i) {
  return this->total_score[i].second;
}

template <typename T> T gResultsCollector<T>::get_score_at(size_t i) {
  return this->total_score[i].first;
}

template class gResultsCollector <gCore::timer_t >;