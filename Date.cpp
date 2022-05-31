#include "Date.h"
#include <iostream>

std::string Date::show_pretty_date() const {
    int int_day=day;
    int int_year=year;
    std::string str_day = std::to_string(int_day);
    std::string str_year = std::to_string(int_year);
    std::string beautiful_month = month;
    std::string beautiful_date, beautiful_day, beautiful_year;

    int i = 0; //сколько цифр в дне
    while( str_day[i] != '\0' ){i++;}

    if (int_day==1){beautiful_day="first";}
    else if (int_day==2){beautiful_day="second";}
    else if (int_day==3){beautiful_day="third";}
    else {beautiful_day=str_day+"th";}

    beautiful_date ="The "+ beautiful_day+" of "+beautiful_month+", "+str_year;
    return beautiful_date;
} //просто чтоб красиво дата выводилась с нулями и все такое

Date &Date::operator=(const Date &equal) {

    if (this == &equal)
        return *this;

    year=equal.year;
    month=equal.month;
    day=equal.day;
    return *this;
}

Date::Date()
{
    day = 20;
    month = "October";
    year = 2022;
}


