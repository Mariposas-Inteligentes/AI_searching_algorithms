// Authors: Luis Solano, Angie Solís, Emilia Víquez

#ifndef GREEDY_BREADTH_FIRST
#define GREEDY_BREADTH_FIRST

#include "common.hpp"
#include "matrix.hpp"

#include <string>
#include <set>
#include <queue>

class GreedyBreadthFirst {
  private:
    // Attributes
    std::shared_ptr<Matrix> initialState;
    std::priority_queue<int> openList;
    std::set<std::string> closedList;
    Common common;

    // Methods
    void printSolution();

  public:
    GreedyBreadthFirst();
    GreedyBreadthFirst(std::string initialState);
    ~GreedyBreadthFirst();
    void solve();
};

#endif  // GREEDY_BREADTH_FIRST