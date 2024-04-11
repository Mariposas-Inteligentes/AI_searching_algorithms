// Authors: Luis Solano, Angie Solís, Emilia Víquez

#ifndef MATRIX
#define MATRIX

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>

#define SIZE 3
#define INVALID -1
#define DIRECTIONS 4
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

class Matrix
{
  friend std::ostream &operator<<(std::ostream &output, Matrix &matrix)
  {
    return matrix.printMatrix(output);
  }

  const int move_row[4] = {-1, 0, 1, 0};
  const int move_col[4] = {0, 1, 0, -1};
  const std::string solution = "012345678";

private:
  std::vector<std::vector<int>> matrix;
  int row0;
  int col0;

public:
  Matrix();
  Matrix(std::vector<std::vector<int>> matrix);
  ~Matrix();
  void fillMatrix(std::string numbers);
  bool verifySolution();
  std::string toString();
  std::ostream &printMatrix(std::ostream &output);
  bool possibleMove(int dir);
  std::shared_ptr<Matrix> movePiece(int dir);
};

#endif
