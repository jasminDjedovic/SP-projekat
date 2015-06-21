#include "worker.h"
#include <string>
#include <iostream>

Worker::Worker(const Worker &b)
{
  _id_worker = b._id_worker;
  _password = b._password;
  _name = b._name;
  _surname = b._surname;  
}

Worker::Worker(Worker &&b)
{
  _id_worker = b._id_worker;
  _password = b._password;
  _name = b._name;
  _surname = b._surname;   
}

Worker& Worker::operator=(Worker&& b)
{
  _id_worker = b._id_worker;
  _password = b._password;
  _name = b._name;
  _surname = b._surname;    

  return *this;
}

Worker& Worker::operator=(const Worker& b)
{
  _id_worker = b._id_worker;
  _password = b._password;
  _name = b._name;
  _surname = b._surname;   
  
  return *this;
}

void Worker::print()
{
  std::cout << "ID: " << _id_worker << std::endl;
  std::cout << "First name: " << _name << std::endl;
  std::cout << "Last name: " << _surname << std::endl;
  std::cout<<"----------------------------------------"<<std::endl;
}
