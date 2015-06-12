#ifndef _CAR_MODEL_H_
#define _CAR_MODEL_H_
#include "manufacturer.h"
#include "date.h"
#include <string>

class CarModel : public Manufacturer
{
  private:
    long int _chasisNumber;
    int _numberOfDoors;
    std::string _color;
    int _engineSize;
    std::string _engineType;
    Date _manufacture_date;
  public:
    CarModel();
    CarModel(const std::string &, const std::string &, const std::string &, long int, int, const std::string &, int, const std::string &, Date&);
    CarModel(const CarModel &);
    CarModel(CarModel &&);
    CarModel &operator=(const CarModel &);
    CarModel &operator=(CarModel &&);

    void print();
};

#endif

