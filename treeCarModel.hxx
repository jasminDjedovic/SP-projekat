#ifndef _TREE_CAR_MODEL_
#define _TREE_CAR_MODEL_
#include "bst.hxx"
#include "carModel.h"
#include "date.h"
#include <string>
#include <fstream>
#include "node.hxx"

class TreeCarModel : public BST<CarModel>
{
  public:
    void addCar();
    void printCar();
    void loadCars();
    NodeBST<CarModel>* searchCar(const long int&);
    void findCar();
    void sellCar();
};

void TreeCarModel::sellCar()
{
  if(isEmpty()==true)
  {
    std::cout<<"There are no cars in database!"<<std::endl;
    return;
  }
  
  long int chasisNumber;

  std::cout << "Insert chasis number for sell: ";
  std::cin >> chasisNumber;

  
  NodeBST<CarModel>* tmp = searchCar(chasisNumber);

  if(tmp == nullptr)
    std::cout << "Car wasn't find in database" << std::endl;
  else
  {
    remove(tmp->getValue());
  }
}

void TreeCarModel::findCar()
{
  if(isEmpty()==true)
  {
    std::cout<<"There are no cars in database!"<<std::endl;
    return;
  }

  long int chasisNumber;

  std::cout << "Insert chasis number for search: ";
  std::cin >> chasisNumber;

  
  NodeBST<CarModel>* tmp = searchCar(chasisNumber);

  if(tmp == nullptr)
    std::cout << "Car wasn't find in database" << std::endl;
  else
  {
    std::cout << "Car information with chasis number: " << chasisNumber << std::endl;
    std::cout << tmp -> getValue() << std::endl;
  }
  
}


NodeBST<CarModel>* TreeCarModel::searchCar(const long int& chasisNumber)
{
  NodeBST<CarModel> *tmp = root;

  while(tmp != nullptr)
  {
    if(tmp -> getValue() == chasisNumber)
      return tmp;
   
    if(tmp -> getValue() < chasisNumber)
      tmp = tmp -> getRightNode();
    else
      tmp = tmp -> getLeftNode();
  }
  return nullptr;
}

void TreeCarModel::loadCars()
{
  std::ifstream file("carDatabase.txt");
  if(!file)
  {
    std::cout<<"Error loading cars from database!"<<std::endl;
    file.close();
  }
  std::string pars;
  while(std::getline(file, pars))
  {
    insert(CarModel(pars));
  }
}

void TreeCarModel::printCar()
{
  if(isEmpty()==true)
  {
    std::cout<<"There are no cars in database!"<<std::endl;
    return;
  }
  std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
  std::cout << "Name" << "\t" << "Model" << "\t" << "Class" << "\t" << "Chasis Number" << "\t" << "Engine Size" << "\t" << "Number of doors " << "\t" << "Color" << "\t" << "Manufacture date" << std::endl;
  std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
  printInorder();
}

void TreeCarModel::addCar()
{
  std::string name, model, Class, color, engineType, date;
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
  std::cout<<"Manufacture date: (DD/MM/YY): ";
  std::cin>>date;

  insert(CarModel(name, model, Class, chasisNumber, numberOfDoors, color, engineSize, engineType, Date(date)));
}
#endif
