#ifndef _DATE_H
#define _DATE_H

#include <string>
#include <iostream>

class Date
{
  private:
    std::string _day;
    std::string _month;
    std::string _year;

  public:
    Date() : _day(""), _month(""), _year("") {}
    Date(const std::string& day, const std::string& month, const std::string& year) {}

    Date(const Date&);
    Date(Date&&);

    Date& operator=(Date &&);
    Date& operator=(const Date &);
    
    /*
    friend ostream& operator<<(ostream& out, const Date& date)
    {
      out << date._day << "." << date._month << "." << date._year;
      return out;
    }
    */

    void print();
};
#endif
