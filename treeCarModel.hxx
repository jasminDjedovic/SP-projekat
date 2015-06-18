#ifndef _TREE_CAR_MODEL_
#define _TREE_CAR_MODEL_
#include "bst.hxx"
#include "carModel.h"
#include <string>

class TreeCarModel : public BST<CarModel>
{
  public:
    void addCar();
};

void TreeCarModel::addCar()
{
  std::string name, model, Class, color, engineType;
  long int chasisNumber;
  int numberOfDoors, engineSize;
  std::cout<<"Please insert car info: "<<std::endl;
  std::cout<<"Manufacturer name: ";
  std::cin>>name;
  std::cout<<"Car model: ";
  std::cin>>model;
  std::cout<<"Class: ";
  std::cin>>Class;
  std::cout<<"Chasis number: ";
  std::cin>>chasisNumber;
  std::cout<<"Engine size [cm3]: ";
  std::cin>>engineSize;
  std::cout<<"Engine type: ";
  std::cin>>engineType;
  std::cout<<"Number of doors (3/5): ";
  std::cin>>numberOfDoors;
  std::cout<<"Color: ";
  std::cin>>color;

  insert(CarModel(name, model, Class, chasisNumber, numberOfDoors, color, engineSize, engineType));
}
#endif
