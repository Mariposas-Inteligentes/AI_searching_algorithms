#ifndef BREADTH_FIRST
#define BREADTH_FIRST

#include "matrix.hpp"
#include "node.hpp"
#include <queue>
#include <set>

class BreadthFirst {
  private:
    Matrix actualMatrix;
    std::queue<Node*> pending;
    std::set<std::string> visited;

  public:
    BreadthFirst();
    BreadthFirst(std::string initial);
    ~BreadthFirst();
    void solve();
    void printAsMatrix(std::string text);
    void printSolution(Node * finalNode);
};

#endif
