#ifndef _CAR_MODEL_H_
#define _CAR_MODEL_H_
#include "manufacturer.h"
#include <string>

class CarModel : public Manufacturer
{
  private:
    long int _chasisNumber;
    int _numberOfDoors;
    std::string _color;
    int _engineSize;
    std::string _engineType;
  public:
    CarModel();
    CarModel(const std::string &, const std::string &, const std::string &, long int, int, const std::string &, int, const std::string &);
    CarModel(const CarModel &);
    CarModel(CarModel &&);
    CarModel &operator=(const CarModel &);
    CarModel &operator=(CarModel &&);

    void print();
};

#endif

