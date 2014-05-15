#include <iostream>
#include "person.h"

using namespace std;

int main()
{
    Person p1("John Doe", "878765868766", new Date(8,11,1983));
    cout << p1.getName() << endl;
    // Get a reference to the actual Date object stored in p1
    Date* date = p1.getBirthDate();
    // ... and change its year
    date->setYear(2013);
    cout << date->getDay() << "/" << date->getMonth() << "/"
         << date->getYear() << endl;
    // Now date2 gets a COPY of the actual object
    Date* date2 = p1.getBirthDate();
    // ... just to show that it was really changed
    // (but note that any changes in date2 won't affect
    // the stored date)
    cout << date2->getDay() << "/" << date2->getMonth() << "/"
         << date2->getYear() << endl;
}
