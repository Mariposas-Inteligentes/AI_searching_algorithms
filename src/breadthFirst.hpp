// Authors: Luis Solano, Angie Solís, Emilia Víquez

#ifndef BREADTH_FIRST
#define BREADTH_FIRST

#include "matrix.hpp"
#include "node.hpp"
#include <queue>
#include <set>
#include <memory>
#include <chrono>

class BreadthFirst {
  private:
    Matrix actualMatrix;
    std::queue<std::shared_ptr<Node>> pending;
    std::set<std::string> visited;
    bool measure;
    std::chrono::_V2::system_clock::time_point start;
    std::chrono::_V2::system_clock::time_point end;
    long size;

  public:
    BreadthFirst();
    BreadthFirst(std::string initial, bool measure);
    ~BreadthFirst();
    void solve();
    void printSolution(std::shared_ptr<Node> finalNode);
};

#endif
