#include "worker.h"
#include <string>
#include <iostream>

Worker::Worker(const Worker &b)
{
  _name = b._name;
  _surname = b._surname;
  _id_worker = b._id_worker;
}

Worker::Worker(Worker &&b)
{
  _name = b._name;
  _surname = b._surname;
  _id_worker = b._id_worker;
}

Worker& Worker::operator=(Worker&& b)
{
  _name = b._name;
  _surname = b._surname;
  _id_worker = b._id_worker;

  return *this;
}

Worker& Worker::operator=(const Worker& b)
{
  _name = b._name;
  _surname = b._surname;
  _id_worker = b._id_worker;

  return *this;
}

void Worker::print()
{
  std::cout << "ID radnika: " << _id_worker << std::endl;
  std::cout << "Ime radnika: " << _name << std::endl;
  std::cout << "Prezime radnika: " << _surname << std::endl;
}
