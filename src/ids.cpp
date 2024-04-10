// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "ids.hpp"

Ids::Ids()
{
  this->initial.fillMatrix("724506831");
}

Ids::Ids(std::string strInitial)
{
  this->initial.fillMatrix(strInitial);
}

Ids::~Ids()
{
}

void Ids::solve()
{
  bool solved = false;
  for (int level = 0; level < LIMIT; ++level)
  {
    solved = checkLevel(level, 0, &initial);
    if (solved)
    {
      this->printSolution();
      break;
    }
  }
  if (!solved)
  {
    std::cout << "No solution was found in " << LIMIT << " levels" << std::endl;
  }
}

bool Ids::checkLevel(int level, int actualLevel, Matrix *actual)
{
  if (level == actualLevel)
  {
    if (actual->verifySolution())
    {
      this->path.push(actual->toString());
      return true;
    }
  }
  else
  {
    for (int dir = 0; dir < DIRECTIONS; ++dir)
    {
      if (actual->possibleMove(dir))
      {
        Matrix *newMatrix = actual->movePiece(dir);
        if (this->checkLevel(level, actualLevel + 1, newMatrix))
        {
          this->path.push(actual->toString());
          return true;
        }
        delete newMatrix;
      }
    }
  }
  return false;
}

void Ids::printAsMatrix(std::string text)
{
  for (int i = 0; i < text.length(); ++i)
  {
    if (i % SIZE == 0)
    {
      std::cout << "\n";
    }

    if (text[i] != '0')
    {
      std::cout << text[i] << " ";
    }
    else
    {
      std::cout << "_ ";
    }
  }
}

void Ids::printSolution()
{
  while (!this->path.empty())
  {
    std::string actualNode = this->path.top();
    this->printAsMatrix(actualNode);
    std::cout << "\n";
    this->path.pop();
  }
}
