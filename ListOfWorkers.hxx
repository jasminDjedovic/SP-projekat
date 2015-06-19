#ifndef WORKERS_HXX
#define WORKERS_HXX
#include<iostream>
#include<string>
#include<fstream>
#include "list.hxx"
#include "worker.h"

class ListOfWorkers:public lista<Worker> {
public:
    void addWorker();
    void printWorker();
    void load_workers();
    void store_workers();
    bool user_check(const std::string& ,const std::string& );
    
};

void ListOfWorkers::printWorker(){
    if(size()==0){
        std::cout<<"List of workers is empty."<<std::endl;
        return;
    }
    for(int i=0;i<size();++i)
        operator[](i).print();
}

bool ListOfWorkers::user_check(const std::string& user,const std::string& pass){
    for(int i=0;i<size();++i){
        if(user==operator[](i).getId() && pass==operator[](i).getPassword())
            return true;
    }
    return false;
}

void ListOfWorkers::load_workers(){
    std::ifstream file("workers.txt");
    if(!file){
        std::cout<<"The file don't exist."<<std::endl;
        file.close();
        return;
    }
    std::string pars,id,pass,name,last_name;
    while(std::getline(file,pars)){
        int id_length=0,pass_length=0,name_length=0,last_name_length=0;
        for(int i=0;pars[i]!='/';++i)
            ++id_length;
        id=pars.substr(0,id_length);
        for(int i=id_length+1;pars[i]!='/';++i)
            ++pass_length;
        pass=pars.substr(id_length+1,pass_length);
        for(int i=id_length+pass_length+2;pars[i]!='/';++i)
            ++name_length;
        name=pars.substr(id_length+pass_length+2,name_length);
        for(int i=id_length+pass_length+name_length+3;pars[i]!='/';++i)
            ++last_name_length;
        last_name=pars.substr(id_length+pass_length+name_length+3,last_name_length);
        push_back(Worker(id,pass,name,last_name));
        
        
    }
    file.close();
}

void ListOfWorkers::store_workers(){
    if(size()==0){
        std::cout<<"List of workers is empty!"<<std::endl;
        return;
    }
    std::ofstream file("workers.txt");
    if(file.is_open()){
        for(int i=0;i<size();++i){
        file<<operator[](i).getId()<<"/"<<operator[](i).getPassword()<<"/"<<operator[](i).getName()<<"/"<<operator[](i).getSur_name()<<"/"<<"\n";
        
    }
        std::cout<<"Data stored sucessfull."<<std::endl;
    }
    else
        std::cout<<"The file don't exist."<<std::endl;
}

void ListOfWorkers::addWorker(){
    std::string id,pass,name,last_name;
    std::cout<<"Please insert worker info: "<<std::endl;
    std::cout<<"Name: ";
    std::cin>>name;
    std::cout<<"Last name: ";
    std::cin>>last_name;
    bool not_exist=true;;
    while(not_exist){
    std::cout<<"User name: ";
    std::cin>>id;
    std::cout<<"Password: ";
    std::cin>>pass;
        if(user_check(id,pass)==false){
            break;
            not_exist=false;
        }
        else{
            std::cout<<"The worker with that user name or password is already in the database. Please try again."<<std::endl;
            continue;
        }
        
    }
    push_back(Worker(id,pass,name,last_name));
}

#endif