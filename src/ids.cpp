// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "ids.hpp"

Ids::Ids() : initial(new Matrix()) {
  std::string defaultStr = "012345678";
  this->initial->fillMatrix(defaultStr);
  this->measure = false;
}

Ids::Ids(std::string strInitial, bool measure)
    : initial(new Matrix()), measure(measure) {
  this->initial->fillMatrix(strInitial);
}

Ids::~Ids(){
}

void Ids::solve() {
  bool solved = false;
  std::chrono::_V2::system_clock::time_point start;
  std::chrono::_V2::system_clock::time_point end;
  long size = 0;

  if (measure) {
    start = std::chrono::high_resolution_clock::now();
  }

  for (int level = 0; level < LIMIT; ++level)
  {
    solved = checkLevel(level, 0, initial);
    if (solved)
    {
      if (measure) {
        end = std::chrono::high_resolution_clock::now();
        size = sizeof(std::string) * this->path.size();
      }

      this->printSolution();
      break;
    }
  }
  if (!solved)
  {
    if (measure) {
      end = std::chrono::high_resolution_clock::now();
      size = sizeof(std::string) * this->path.size();
    }
    std::cout << "No solution was found in " << LIMIT << " levels" << std::endl;
  }

  if (measure) {
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken in IDS: " << diff.count() 
                  <<  "   memory used:  " << size << std::endl;
  }
}

bool Ids::checkLevel(int level, int actualLevel, std::shared_ptr<Matrix> actual) {
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
        std::shared_ptr<Matrix> newMatrix = actual->movePiece(dir);
        if (this->checkLevel(level, actualLevel + 1, newMatrix))
        {
          this->path.push(actual->toString());
          return true;
        }
      }
    }
  }
  return false;
}

void Ids::printAsMatrix(std::string text) {
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

void Ids::printSolution() {
  while (!this->path.empty())
  {
    std::string actualNode = this->path.top();
    std::cout << this->common.printAsMatrix(actualNode, SIZE);
    std::cout << "\n";
    this->path.pop();
  }
}
