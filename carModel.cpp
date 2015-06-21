#include "carModel.h"
#include "manufacturer.h"
#include "date.h"
#include <iostream>
#include <fstream>
#include <string>

CarModel::CarModel()
{
  Manufacturer();
  _chasisNumber = 0;
  _numberOfDoors = 0;
  _color = "";
  _engineSize = 0;
  _engineType = "";
  _price = 0;
}

CarModel::CarModel(const std::string& a)
{
  _name = a.substr(0, 12);
  _model = a.substr(12, 11);
  _class = a.substr(23, 12); 
  _chasisNumber = stoi(a.substr(35, 6));
  _engineSize = stoi(a.substr(42, 4));
  _engineType  = a.substr(47, 8);
  _numberOfDoors = stoi(a.substr(55, 1));
  _color = a.substr(57, 7);
  _manufacture_date = Date(a.substr(64, 12));
  _price = stoi(a.substr(77, 5));
}

CarModel::CarModel(const std::string &name, const std::string &model, const std::string &Class, long int chasisNumber, int numberOfDoors, const std::string &color, int engineSize, const std::string &engineType, const Date &manufacture_date, int price)
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
  _price = price;
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
  _price = b._price;
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
  _price = b._price;
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
  _price = b._price;
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
  _price = b._price;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const CarModel& car)
{

  out<<car._name<<"\t"<<car._model<<"\t"<<car._class<<"\t"<<car._chasisNumber<<"\t"<<car._engineSize<<"\t"<<car._engineType<<"\t"<<car._numberOfDoors<<"\t"<<car._color<<"\t";
  car._manufacture_date.print();
  out<<"\t"<<car._price<<"€";
  return out;
}

bool CarModel::operator==(const CarModel& other) const {return (_chasisNumber == other._chasisNumber);}
bool CarModel::operator!=(const CarModel& other) const {return (_chasisNumber != other._chasisNumber);}
bool CarModel::operator <(const CarModel& other) const {return (_chasisNumber < other._chasisNumber);}
bool CarModel::operator >(const CarModel& other) const {return (_chasisNumber > other._chasisNumber);}
bool CarModel::operator <=(const CarModel& other) const {return (_chasisNumber <= other._chasisNumber);}
bool CarModel::operator >=(const CarModel& other) const {return (_chasisNumber >= other._chasisNumber);}

bool CarModel::operator==(const long int& chasisNumber) const
{
  return _chasisNumber == chasisNumber;
}

bool CarModel::operator<(const long int& chasisNumber) const
{
  return _chasisNumber < chasisNumber;
}

void CarModel::printToFile()
{
  std::ofstream out("carDatabase.txt", std::ofstream::app);

  if(out.is_open())
  {
    out<<_name<<"\t"<<_model<<"\t"<<_class<<"\t"<<_chasisNumber<<"\t"<<_engineSize<<"\t"<<_engineType<<"\t"<<_numberOfDoors<<"\t"<<_color<<"\t";
    //_manufacture_date.print();
    out<<"\t"<<_price<<"€";
  }
  else
    std::cout<<"Error opening file!"<<std::endl;


}
