#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome, string cpf)
{
  this->nome = nome;
  this->cpf = cpf;
}

string Pessoa::getNome() { return nome; }

string Pessoa::getCPF() { return cpf; }

int Pessoa::calcDV1()
{
  int factor = 2, sum = 0;
  for (auto it = cpf.begin(); it != cpf.end(); it++)
  {
    if (*it == '.') continue;
    if (*it == '-') break;
    
    sum += factor * (*it - '0');
    factor++;
  }

  int mod = (sum * 10) % 11;
    
  return mod == 10 ? 0 : mod;
}

int Pessoa::calcDV2()
{
  return 0;
}
