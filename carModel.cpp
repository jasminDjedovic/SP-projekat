#include "carModel.h"
#include "manufacturer.h"
#include "date.h"
#include <iostream>

CarModel::CarModel()
{
  Manufacturer();
  _chasisNumber = 0;
  _numberOfDoors = 0;
  _color = "";
  _engineSize = 0;
  _engineType = "";
}
CarModel::CarModel(const std::string &name, const std::string &model, const std::string &Class, long int chasisNumber, int numberOfDoors, const std::string &color, int engineSize, const std::string &engineType, Date &manufacture_date)
{
  _name = name;
  _model = model;
  _class = Class;
  _chasisNumber = chasisNumber;
  _numberOfDoors = numberOfDoors;
  _color = color;
  _engineSize = engineSize;
  _engineType = engineType;
  _manufacture_date = manufacture_date;
}
CarModel::CarModel(const CarModel &b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
  _chasisNumber = b._chasisNumber;
  _numberOfDoors = b._numberOfDoors;
  _color = b._color;
  _engineSize = b._engineSize;
  _engineType = b._engineType;
  _manufacture_date = b._manufacture_date;
}
CarModel::CarModel(CarModel &&b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
  _chasisNumber = b._chasisNumber;
  _numberOfDoors = b._numberOfDoors;
  _color = b._color;
  _engineSize = b._engineSize;
  _engineType = b._engineType;
  _manufacture_date = b._manufacture_date;
}
CarModel &CarModel::operator=(const CarModel &b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
  _chasisNumber = b._chasisNumber;
  _numberOfDoors = b._numberOfDoors;
  _color = b._color;
  _engineSize = b._engineSize;
  _engineType = b._engineType;
  _manufacture_date = b._manufacture_date;
  return *this;
}
CarModel &CarModel::operator=(CarModel &&b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
  _chasisNumber = b._chasisNumber;
  _numberOfDoors = b._numberOfDoors;
  _color = b._color;
  _engineSize = b._engineSize;
  _engineType = b._engineType;
  _manufacture_date = b._manufacture_date;
  return *this;
}
void CarModel::print()
{
  std::cout<<"Proizvodac: "<<_name<<std::endl;
  std::cout<<"Model: "<<_model<<std::endl;
  std::cout<<"Tip: "<<_class<<std::endl;
  std::cout<<"Zapremina motora: "<<_engineSize<<std::endl;
  std::cout<<"Tip motora: "<<_engineType<<std::endl;
  std::cout<<"Broj vrata: "<<_numberOfDoors<<std::endl;
  std::cout<<"Boja: "<<_color<<std::endl;
  std::cout <<"Datum proizvodnje automobila: ";
  _manufacture_date.print();
}

bool CarModel::operator==(const CarModel& other) const {return (_chasisNumber == other._chasisNumber);}
bool CarModel::operator!=(const CarModel& other) const {return (_chasisNumber != other._chasisNumber);}
bool CarModel::operator <(const CarModel& other) const {return (_chasisNumber < other._chasisNumber);}
bool CarModel::operator >(const CarModel& other) const {return (_chasisNumber > other._chasisNumber);}
bool CarModel::operator <=(const CarModel& other) const {return (_chasisNumber <= other._chasisNumber);}
bool CarModel::operator >=(const CarModel& other) const {return (_chasisNumber >= other._chasisNumber);}
