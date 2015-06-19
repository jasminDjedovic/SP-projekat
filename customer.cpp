#include "customer.h"
#include "date.h"
#include <string>
#include <iostream>

Customer::Customer(const Customer &b)
{
  _name = b._name;
  _surname = b._surname;
  _JMBG = b._JMBG;
  _car = b._car;
  _date = b._date;
}

Customer::Customer(Customer &&b)
{
  _name = b._name;
  _surname = b._surname;
  _JMBG = b._JMBG;
  _car = b._car;
  _date = b._date;
}

Customer& Customer::operator=(Customer&& b)
{
  _name = b._name;
  _surname = b._surname;
  _JMBG = b._JMBG;
  _car = b._car;
  _date = b._date;

  return *this;
}

Customer& Customer::operator=(const Customer& b)
{
  _name = b._name;
  _surname = b._surname;
  _JMBG = b._JMBG;
  _car = b._car;
  _date = b._date;

  return *this;
}

void Customer::print()
{
  std::cout << "Ime kupca: " << _name << std::endl;
  std::cout << "Prezime kupca: " << _surname << std::endl;
  std::cout << "JMBG kupca: " << _JMBG << std::endl;
  //std::cout << "Datum kupovine automobila: " << _date;
  std::cout << "Datum kupovine automobila: ";
  _date.print();
  std::cout << "Informacije o kupljenom automobilu: " << std::endl;
  //_car.print();
}
