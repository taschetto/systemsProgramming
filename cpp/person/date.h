#ifndef DATE_H
#define DATE_H

class Date
{
    public:

    Date();
    Date(int day, int mon, int year);
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int day);
    void setMonth(int mon);
    void setYear(int year);

    private:

    int day, month, year;
};

#endif // DATE_H
