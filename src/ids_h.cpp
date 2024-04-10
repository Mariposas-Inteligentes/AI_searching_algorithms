// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "ids_h.hpp"

Ids_H::Ids_H()
{
  this->initial.fillMatrix("724506831");
}

Ids_H::Ids_H(std::string strInitial)
{
  this->initial.fillMatrix(strInitial);
}

Ids_H::~Ids_H()
{
}

void Ids_H::solve()
{
  bool solved = false;
  
  // TODO(Angie): IDS* logic

  if (!solved)
  {
    std::cout << "No solution was found in " << LIMIT << " levels" << std::endl;
  }
}
