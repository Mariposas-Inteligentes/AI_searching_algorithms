// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "ids_h.hpp"

Ids_H::Ids_H(): initial(new Matrix())
{
  this->initial->fillMatrix("724506831");
  this->lowestCost = INT16_MAX;
}

Ids_H::Ids_H(std::string strInitial): initial(new Matrix())
{
  this->initial->fillMatrix(strInitial);
  this->lowestCost = INT16_MAX;
}

Ids_H::~Ids_H()
{
}

void Ids_H::solve()
{
  int nextLevel = 0;
  bool solved = false;

  while (!solved) {
    solved = this->checkLevel(nextLevel, 0, initial);
    nextLevel += this->lowestCost;
    this->lowestCost = INT16_MAX;
  }

  if (solved) {
    this->printSolution();
  }
  else {
    std::cout << "No solution was found in " << LIMIT << " levels" << std::endl;
  }
}

bool Ids_H::checkLevel(int level, int actualLevel, std::shared_ptr<Matrix> actual) {
  if (level == actualLevel) {  // This is the desired level
    if (actual->verifySolution()) {  // A solution was found
      this->path.push(actual->toString());  // Save the path
      return true;
    }
    else {  // This is the level, but it is not a solution
      // Check if the cost is lower than the last found
      int cost = this->common.heuristic(actual->toString());
      if (cost < this->lowestCost) {
        this->lowestCost = cost;
      }
    }
  } else {  // This is not the desired level yet
    for (int dir = 0; dir < DIRECTIONS; ++dir) {
      if (actual->possibleMove(dir)) {
        std::shared_ptr<Matrix> newMatrix = actual->movePiece(dir);
        if (this->checkLevel(level, actualLevel + 1, newMatrix)) {
          this->path.push(actual->toString());
          return true;
        }
      }
    }
  }
  return false;
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
