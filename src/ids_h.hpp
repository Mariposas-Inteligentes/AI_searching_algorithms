// Authors: Luis Solano, Angie Solís, Emilia Víquez

#ifndef IDS_H
#define IDS_H

#include "common.hpp"
#include "matrix.hpp"

#include <iostream>
#include <stack>
#include <string>

#define LIMIT 40320

class Ids_H
{
  private:
    std::shared_ptr<Matrix> initial;
    Common common;
    std::stack<std::string> path;
    int lowestCost;

    bool checkLevel(int level, int actualLevel, std::shared_ptr<Matrix> actual);
    void printSolution();

  public:
    Ids_H();
    Ids_H(std::string strInitial);
    ~Ids_H();
    void solve();
};

#endif
