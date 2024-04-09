#ifndef MATRIX
#define MATRIX

#include <string>
#include <sstream>
#include <iostream>

#define SIZE 3
#define INVALID -1
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

private:
  int **matrix;
  int row0;
  int col0;

public:
  Matrix();
  Matrix(int **matrix);
  ~Matrix();
  int *operator[](int index);
  bool verifySolution(std::string solution);
  std::string toString();
  std::ostream &printMatrix(std::ostream &output);
  bool possibleMove(int dir);
  Matrix *movePiece(int dir);
};

#endif
