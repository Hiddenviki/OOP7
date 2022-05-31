#pragma once
#include <string>


class Date {
    friend class Supplier;
private:
    int day;
    std::string month;
    int year;


public:

    Date();
    std::string show_pretty_date() const;
    Date& operator = (const Date &equal);

};
