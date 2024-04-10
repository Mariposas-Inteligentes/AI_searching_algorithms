// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "common.hpp"

int Common::heuristic(const std::string actual) {
  int cost = 0;
  for (int pos = 0; pos < 9; ++pos) {
    // This obtains the minimum distance to the correct position
    cost += ((int) this->distance[((int) actual[pos]) - 48][pos]) - 48;
  }
  return cost;
}