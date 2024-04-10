// Authors: Luis Solano, Angie Solís, Emilia Víquez

#ifndef IDS
#define IDS

#include "matrix.hpp"
#include <iostream>
#include <stack>
#include <string>

#define LIMIT 40320

class Ids
{
private:
  Matrix initial;
  std::stack<std::string> path;

  void printSolution();

public:
  Ids();
  Ids(std::string strInitial);
  ~Ids();
  void solve();
  bool checkLevel(int level, int actualLevel, Matrix *actual);
  void printAsMatrix(std::string text);
};

#endif