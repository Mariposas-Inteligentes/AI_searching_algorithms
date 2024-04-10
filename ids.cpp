#include "ids.hpp"

Ids::Ids()
{
  this->initial.fillMatrix("724506831");
}

Ids::~Ids()
{
}

void Ids::solve()
{
  for (int level = 0; level < LIMIT; ++level)
  {
    if (checkLevel(level, 0, &initial))
    {
      break;
    }
  }
}

bool Ids::checkLevel(int level, int actualLevel, Matrix *actual)
{
  if (level == actualLevel && actual->verifySolution())
  {
    this->path.push(actual->toString());
    return true;
  }
  else
  {
    for (int dir = 0; dir < DIRECTIONS; dir++)
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
}
