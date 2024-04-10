#ifndef IDS
#define IDS

#include "matrix.hpp"
#include <stack>
#include <string>

#define LIMIT 40320

class Ids
{
private:
  Matrix initial;
  std::stack<std::string> path;

public:
  Ids();
  ~Ids();
  void solve();
  bool checkLevel(int level, int actualLevel, Matrix *actual);
};

#endif