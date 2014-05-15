#include "person.h"

Person::Person(string name, string cpf, Date* bDate)
{
    this->name = name;
    this->cpf = cpf;
    this->birthDate = bDate;
}

string Person::getName()
{
    return name;
}

string Person::getCPF()
{
    return cpf;
}

Date* Person::getBirthDate()
{
    return birthDate;
}

