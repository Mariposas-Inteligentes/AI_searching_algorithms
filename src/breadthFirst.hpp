#ifndef BREADTH_FIRST
#define BREADTH_FIRST

#include "matrix.hpp"
#include "node.hpp"
#include <queue>
#include <set>
#include <memory>

class BreadthFirst {
  private:
    Matrix actualMatrix;
    std::queue<std::shared_ptr<Node>> pending;
    std::set<std::string> visited;

  public:
    BreadthFirst();
    BreadthFirst(std::string initial);
    ~BreadthFirst();
    void solve();
    void printSolution(std::shared_ptr<Node> finalNode);
};

#endif
