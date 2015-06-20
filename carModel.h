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
    int _price;
  public:
    CarModel();
    CarModel(const std::string &, const std::string &, const std::string &, long int, int, const std::string &, int, const std::string &, const Date&, int);
    CarModel(const CarModel &);
    CarModel(CarModel &&);
    CarModel &operator=(const CarModel &);
    CarModel &operator=(CarModel &&);
    CarModel(const std::string&);

    bool operator==(const long int&) const;
    bool operator<(const long int&) const;

    bool operator ==(const CarModel&) const;
    bool operator !=(const CarModel&) const;
    bool operator <(const CarModel&) const;
    bool operator >(const CarModel&) const;
    bool operator <=(const CarModel&) const;
    bool operator >=(const CarModel&) const;

    friend std::ostream& operator<<(std::ostream&, const CarModel&);


};

#endif

