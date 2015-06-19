#ifndef _WORKER_H
#define _WORKER_H

#include <string>

class Worker
{
  private:
    string _id_worker;
    string _password;
    std::string _name;
    std::string _surname;

  public:
    Worker() : _id_worker(""), _password(""), _name(""), _surname("") {}

    Worker(const std::string& id_worker, const std::string& password, const string& name,const string& surname) : _id_worker(id_worker), _password(password), _name(name), _surname(surname) {}

    Worker(Worker&&);
    Worker(const Worker&);

    Worker& operator=(Worker &&);
    Worker& operator=(const Worker &);

    void print();
};
#endif
