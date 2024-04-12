// Authors: Luis Solano, Angie Solís, Emilia Víquez

#include "matrix.hpp"

Matrix::Matrix(): matrix(3, std::vector<int>(3)) {
  this->row0 = INVALID;
  this->col0 = INVALID;
}

Matrix::Matrix(std::vector<std::vector<int>>matrix) : matrix(3, std::vector<int>(3)) {
  for (int row = 0; row < SIZE; ++row)
  {
    for (int col = 0; col < SIZE; ++col)
    {
      this->matrix[row][col] = matrix[row][col];
      if (this->matrix[row][col] == 0)
      {
        this->row0 = row;
        this->col0 = col;
      }
    }
  }
}

Matrix::~Matrix() {
}

void Matrix::fillMatrix(std::string numbers) {
  int string_count = 0;
  for (int row = 0; row < SIZE; ++row)
  {
    for (int col = 0; col < SIZE; ++col)
    {
      this->matrix[row][col] = ((int)numbers[string_count++]) - 48;
      if (this->matrix[row][col] == 0)
      {
        this->col0 = col;
        this->row0 = row;
      }
    }
  }
}

std::string Matrix::toString() {
  std::stringstream solution;
  for (int row = 0; row < SIZE; ++row)
  {
    for (int col = 0; col < SIZE; ++col)
    {
      solution << this->matrix[row][col];
    }
  }
  return solution.str();
}

bool Matrix::verifySolution() {
  return this->toString() == this->solution;
}

std::ostream &Matrix::printMatrix(std::ostream &output) {
  for (int row = 0; row < SIZE; ++row)
  {
    for (int col = 0; col < SIZE; ++col)
    {
      output << this->matrix[row][col];
      output << " ";
    }
    output << "\n";
  }
  return output;
}

bool Matrix::possibleMove(int dir) {
  if (this->row0 + move_row[dir] >= 0 && this->row0 + move_row[dir] < SIZE)
  {
    if (this->col0 + move_col[dir] >= 0 && this->col0 + move_col[dir] < SIZE)
    {
      return true;
    }
  }
  return false;
}

std::shared_ptr<Matrix> Matrix::movePiece(int dir) {
  std::shared_ptr<Matrix> newMatrix (new Matrix(this->matrix));
  newMatrix->matrix[newMatrix->row0][newMatrix->col0] =
      newMatrix->matrix[newMatrix->row0 + this->move_row[dir]][newMatrix->col0 + this->move_col[dir]];
  newMatrix->row0 += this->move_row[dir];
  newMatrix->col0 += this->move_col[dir];
  newMatrix->matrix[newMatrix->row0][newMatrix->col0] = 0;
  return newMatrix;
}
