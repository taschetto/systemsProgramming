#include "matrix.h"
#include <iostream>

Matrix::Matrix(int i, int j)
  : lines(i)
  , columns(j)
{
  matrix = new int*[lines];
  for (int i = 0; i < lines; i++)
    matrix[i] = new int[columns];
}

Matrix::~Matrix()
{
  for (int i = 0; i < lines; i++)
    delete[] matrix[i];
  delete[] matrix;
}

int Matrix::get(int i, int j)
{
  return matrix[i][j];
}

void Matrix::set(int i, int j, int value)
{
  matrix[i][j] = value;
}

void Matrix::show()
{
  for (int i = 0; i < lines; i++)
  {
    for (int j = 0; j < columns; j++)
      std::cout << matrix[i][j] << " ";
    std::cout << std::endl;
  }
}
