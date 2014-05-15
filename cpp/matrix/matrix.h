#pragma once

class Matrix
{
private:
  int** matrix;
  int lines;
  int columns;

	public:
    Matrix(int, int);
    ~Matrix();
    int get(int, int);
    void set(int, int, int);
    void show();
};
