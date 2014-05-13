#pragma once
#include <string>

using namespace std;

class Pessoa
{
  private:
    string nome;
    string cpf;

  public:
    Pessoa(string nome, string cpf);
    string getNome();
    string getCPF();
    int calcDV1();
    int calcDV2();
};
