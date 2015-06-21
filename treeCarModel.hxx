#ifndef _TREE_CAR_MODEL_
#define _TREE_CAR_MODEL_
#include "bst.hxx"
#include "carModel.h"
#include "date.h"
#include <string>
#include <fstream>
#include "node.hxx"
#include <iomanip>
#include <time.h>
#include "worker.h"
#include "ListOfWorkers.hxx"
#include <stdio.h>

class TreeCarModel : public BST<CarModel>
{
  public:
    void addCar();
    void printCar();
    void loadCars();
    void storeCars();
    NodeBST<CarModel>* searchCar(const long int&);
    void findCar();
    void sellCar(const std::string&,ListOfWorkers&);
    void storeBill(const CarModel&,Worker) const;
    std::string get_current_time()const;
    Worker worker_info(const std::string&,ListOfWorkers&);
    void inorderToFile(NodeBST<CarModel> *);
};

Worker TreeCarModel::worker_info(const std::string& worker_user,ListOfWorkers& all_workers){
    for(int i=0;i<all_workers.size();++i){
        if(worker_user==all_workers[i].getId())
            return all_workers[i];
    }
    return all_workers[all_workers.size()-1];
}

std::string TreeCarModel::get_current_time()const{
    time_t pc_time;
    tm* time_info;
    time(&pc_time);
    time_info=localtime(&pc_time);
    return asctime(time_info);
}

void TreeCarModel::storeBill(const CarModel& car,Worker worker) const {
    std::string current_time=get_current_time();
    std::string file_name="bills/"+current_time;
    std::ofstream file;
    int price=car.getPrice();
    float pdv=price*0.17;
    file.open(file_name);
    if(file.is_open()){
        file<<std::string(112,'-')<<"\n";
        file<<"Date/Time -> "<<current_time;
        file<<std::string(112,'-')<<"\n";
        file<<"Worker -> "<<worker.getName()<<" "<<worker.getSur_name()<<"\n";
        file<<std::string(112,'-')<<"\n";
        file<<"Name"<<std::string(11, ' ')<<"Model"<<std::string(8, ' ')<<"Class"<<std::string(8, ' ');
        file<<"ChasisN    "<<"EngineS    "<<"EngineT   "<<"Doors    "<<"Color    "<<"Production"<<std::string(4,' ')<<"Price"<<std::endl;
        file<<car<<"\n";
        file<<std::string(112,'-')<<"\n";
        file<<"PDV: "<<pdv<<"\n";
        file<<"Price+PDV: "<<price+pdv<<"\n";
        file<<std::string(112,'-')<<"\n";
    }
    file.close();
}

void TreeCarModel::storeCars()
{
  if(isEmpty()==true)
  {
    std::cout<<"There are no cars in database!"<<std::endl;
    return;
  }
  std::remove("carDatabase.txt");
  inorderToFile(root);
}
void TreeCarModel::inorderToFile(NodeBST<CarModel> *node)
{
  //static std::ofstream file("carDatabase.txt");
  if(node->getLeftNode() != nullptr)
    inorderToFile(node->getLeftNode());

  node->getValue().printToFile();
  //file<<node->getValue();

  if(node->getRightNode() != nullptr)
    inorderToFile(node->getRightNode());
}

void TreeCarModel::sellCar(const std::string& worker_user,ListOfWorkers& all_workers)
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
    
    storeBill(tmp->getValue(),worker_info(worker_user,all_workers));
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
    
    std::cout<<std::string(112,'-')<<std::endl;  
    std::cout<<"Name"<<std::string(11, ' ')<<"Model"<<std::string(8, ' ')<<"Class"<<std::string(8, ' ');
    std::cout<<"ChasisN    "<<"EngineS    "<<"EngineT   "<<"Doors    "<<"Color    "<<"Production"<<std::string(4,' ')<<"Price"<<std::endl;
    std::cout<<std::string(112,'-')<<std::endl;
    
    std::cout << tmp -> getValue() << std::endl;
    std::cout<<std::string(112,'-')<<std::endl;
    std::cout<<std::endl;
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

  std::cout<<std::string(112,'-')<<std::endl;  
  std::cout<<"Name"<<std::string(11, ' ')<<"Model"<<std::string(8, ' ')<<"Class"<<std::string(8, ' ');
  std::cout<<"ChasisN    "<<"EngineS    "<<"EngineT   "<<"Doors    "<<"Color    "<<"Production"<<std::string(4,' ')<<"Price"<<std::endl;
  std::cout<<std::string(112,'-')<<std::endl;

  printInorder();
  std::cout<<std::endl;
}

void TreeCarModel::addCar()
{
  std::string name, model, Class, color, engineType, date;
  long int chasisNumber;
  int numberOfDoors, engineSize, price;
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
  std::cout<<"Price: ";
  std::cin>>price;

  insert(CarModel(name, model, Class, chasisNumber, numberOfDoors, color, engineSize, engineType, Date(date), price));
}
#endif
