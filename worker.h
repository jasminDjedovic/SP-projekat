#ifndef _WORKER_H
#define _WORKER_H

#include <string>

class Worker
{
  private:
    std::string _name;
    std::string _surname;
    int _id_worker;

  public:
    Worker() : _name(""), _surname(""), _id_worker(0) {}

    Worker(const std::string& name, const std::string& surname, int id_worker) : _name(name), _surname(surname), _id_worker(id_worker) {}

    Worker(Worker&&);
    Worker(const Worker&);

    Worker& operator=(Worker &&);
    Worker& operator=(const Worker &);

    void print();
};
#endif
