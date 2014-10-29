#include <iostream>
#include "pessoa.h"

int main()
{
  Pessoa p1("Guilherme Taschetto", "000.000.000-00");
  std::cout << p1.getCPF() << endl;
  std::cout << p1.calcDV1() << endl;
  return 0;
}
