// Authors: Luis Solano, Angie Solís, Emilia Víquez

#ifndef GREEDY_BREADTH_FIRST
#define GREEDY_BREADTH_FIRST

#include "common.hpp"
#include "matrix.hpp"
#include "node.hpp"

#include <string>
#include <set>
#include <queue>

class GreedyBreadthFirst {
  private:
    // Attributes
    std::shared_ptr<Matrix> initialState;
    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, CompareNodes> openList;
    std::set<std::string> closedList;
    Matrix actualMatrix;
    Common common;

    // Methods
    void init(std::string initialState);
    void findMovements(std::shared_ptr<Node>& actualNode);
    void printSolution(std::shared_ptr<Node> finalNode);

  public:
    GreedyBreadthFirst();
    GreedyBreadthFirst(std::string initialState);
    ~GreedyBreadthFirst();
    void solve();
};

#endif  // GREEDY_BREADTH_FIRST