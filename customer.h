#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>
#include "carModel.h"
#include "date.h"

class Customer
{
  private:
    std::string _name;
    std::string _surname;
    std::string _JMBG;
    CarModel _car;
    Date _date;
  public:
    Customer() : _name(""), _surname(""), _JMBG(""), _car(), _date() {}
    Customer(const std::string& name, const std::string& surname, const std::string& JMBG, CarModel car, Date date) : _name(name), _surname(surname), _JMBG(JMBG), _car(car), _date(date) {}

    Customer(Customer&&);
    Customer(const Customer&);

    Customer& operator=(Customer &&);
    Customer& operator=(const Customer &);

    void print();
};
#endif
