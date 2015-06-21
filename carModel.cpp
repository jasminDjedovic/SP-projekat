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
  _name = a.substr(0, 15);
  _model = a.substr(15, 13);
  _class = a.substr(28, 13); 
  _chasisNumber = stoi(a.substr(41, 6));
  _engineSize = stoi(a.substr(48, 4));
  _engineType  = a.substr(53, 10);
  _numberOfDoors = stoi(a.substr(63, 1));
  _manufacture_date = Date(a.substr(65,10));
  _color = a.substr(76, 9);
  _price = stoi(a.substr(85));
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
  
  out<<car._name;
  for(int i=0; i<15-car._name.length();++i) out<<" ";
  out<<car._model;
  for(int i=0; i<13-car._model.length();++i) out<<" ";
  out<<car._class;
  for(int i=0; i<13-car._class.length();++i) out<<" ";
  out<<car._chasisNumber<<"      "<<car._engineSize<<"      "<<car._engineType;
  for(int i=0; i<10-car._engineType.length();++i) out<<" ";
  out<<car._numberOfDoors<<"        "<<car._color;
  for(int i=0; i<9-car._color.length();++i) out<<" ";
  out<<car._manufacture_date.getDay()<<"/"<<car._manufacture_date.getMonth()<<"/"<<car._manufacture_date.getYear();
  out<<"    "<<car._price;
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
    out<<_name;
    for(int i=0; i<15-_name.length();++i) out<<" ";
    out<<_model;
    for(int i=0; i<13-_model.length();++i) out<<" ";
    out<<_class;
    for(int i=0; i<13-_class.length();++i) out<<" ";
    out<<_chasisNumber<<" "<<_engineSize<<" "<<_engineType;
    for(int i=0; i<10-_engineType.length();++i) out<<" ";
    out<<_numberOfDoors<<" ";
    out<<_manufacture_date.getDay()<<"/"<<_manufacture_date.getMonth()<<"/"<<_manufacture_date.getYear();
    out<<" "<<_color;
    for(int i=0; i<9-_color.length();++i) out<<" ";
    out<<_price<<"\n";
  }
  else
    std::cout<<"Error opening file!"<<std::endl;


}
