#include "matrix.h"

int main()
{
  Matrix* m = new Matrix(10, 15);

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 15; j++)
      m->set(i, j, i * j);
  m->show();
  return 0;
}
