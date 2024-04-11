// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "ids_h.hpp"

Ids_H::Ids_H(): initial(new Matrix())
{
  this->initial->fillMatrix("724506831");
}

Ids_H::Ids_H(std::string strInitial): initial(new Matrix())
{
  this->initial->fillMatrix(strInitial);
}

Ids_H::~Ids_H()
{
}

void Ids_H::solve()
{
  bool solved = false;
  
  solved = this->checkLevel(0, 0, initial);

  if (solved) {
    this->printSolution();
  }
  else {
    std::cout << "No solution was found in " << LIMIT << " levels" << std::endl;
  }
}

bool Ids_H::checkLevel(int level, int actualLevel, std::shared_ptr<Matrix> actual) {
  if (level == actualLevel) {
    if (actual->verifySolution()) {
      this->path.push(actual->toString());
      return true;
    }
    else {  // This is the level, but it is not a solution
      // First, find the next path
      std::shared_ptr<Matrix> newMatrix = this->findNextLevel(actual, &level);
      // Second, recursive call if less than the limit
      if (level <= LIMIT) {
        if (this->checkLevel(level, actualLevel, newMatrix)) {
          this->path.push(actual->toString());
          return true;
        }
      }
    }
  }
  return false;
}

std::shared_ptr<Matrix>  Ids_H::findNextLevel(std::shared_ptr<Matrix> actual, int* actualCost) {
  std::shared_ptr<Matrix> desiredMatrix(0);
  int minCost = INT64_MAX;
  int cost = 0;

  for (int dir = 0; dir < DIRECTIONS; ++dir)
  {
    if (actual->possibleMove(dir))
    {
      std::shared_ptr<Matrix> newMatrix = actual->movePiece(dir);
      cost = common.heuristic(newMatrix->toString());
      if (cost < minCost) {
        cost = minCost;
        desiredMatrix = newMatrix;
      }
    }
  }

  // The new cost is updated
  *actualCost += cost;

  return desiredMatrix;
}

void Ids_H::printSolution()
{
  while (!this->path.empty())
  {
    std::string actualNode = this->path.top();
    std::cout << this->common.printAsMatrix(actualNode, SIZE);
    std::cout << "\n";
    this->path.pop();
  }
}
