#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <string>

using namespace std;

class Person
{
    public:

    Person(string name, string cpf, Date* bDate);
    string getName();
    string getCPF();
    // Returning a reference is good when you want the user
    // to be able to CHANGE the Date object contents
    // (if not, then define it as an object - without the &)
    Date* getBirthDate();

    private:

    string name;
    string cpf;
    Date* birthDate;
};

#endif // PERSON_H
