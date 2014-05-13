#include <iostream>
#include "pessoa.h"

int main()
{
  Pessoa p1("Guilherme Taschetto", "011.141.170-05");
  std::cout << p1.getCPF() << endl;
  std::cout << p1.calcDV1() << endl;
  return 0;
}
