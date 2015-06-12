#include "date.h"
#include <string>

#include <iostream>

Date::Date(const Date &b)
{
  _day = b._day;
  _month = b._month;
  _year = b._year;
}

Date::Date(Date &&b)
{
  _day = b._day;
  _month = b._month;
  _year = b._year;
}

Date& Date::operator=(Date&& b)
{
  _day = b._day;
  _month = b._month;
  _year = b._year;

  return *this;
}

Date& Date::operator=(const Date& b)
{
  _day = b._day;
  _month = b._month;
  _year = b._year;

  return *this;
}

void Date::print()
{
  std::cout << _day << "." << _month << "." << _year;
}
