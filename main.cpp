#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<unistd.h>
#include<cstdlib>
#include "worker.h"
#include "treeCarModel.hxx"
#include "ListOfWorkers.hxx"

using namespace std;

string admin_user="admin";
const char* admin_pass="admin";

int admin_login();
int worker_login();

int main(){
    TreeCarModel carDatabase;
    ListOfWorkers workerDatabase;
    workerDatabase.load_workers();
    bool log;
    bool main_log=false;
    bool editedCars = false;
    bool editedWorkers = false;
    int admin_log;
    int worker_log;
    while(main_log==false){
             string user;
             char* password;
             cout<<"User name: ";
             cin>>user;
             password=getpass("Password: ");
             if(user==admin_user && strcmp(password,admin_pass)==0){
                carDatabase.loadCars();
                admin_log=-1;
                while(admin_log!=0){
                    switch (admin_log=admin_login()) {
                        case 1:
                            carDatabase.addCar();
                            editedCars = true;
                            break;
                        case 2:
                            carDatabase.printCar();
                            break;
                        case 3:
                            workerDatabase.addWorker();
                            editedWorkers = true;
                            break;
                        case 4:
                            workerDatabase.printWorker();
                            break;
                        case 5:
                            carDatabase.findCar();
                            break;
                        case 0:
                            main_log=true;
                            break;
                        default:
                            cout<<"Wrong choice!"<<endl;
                            break;
                    }
                }
                }
                else if(workerDatabase.user_check(user,password)){
                carDatabase.loadCars();
                worker_log=-1;
                while(worker_log!=0){
                    switch (worker_log=worker_login()) {
                        case 1:
                            carDatabase.printCar();
                            break;
                        case 2:
                            carDatabase.findCar();
                            break;
                        case 3:
                            carDatabase.sellCar();
                            editedCars = true;
                            cout<<"Car marked as sold!"<<endl;
                            break;
                        case 0:
                            main_log=true;
                            break;
                        default:
                            cout<<"Wrong choice!"<<endl;
                            break;
                    }
                }
                }
                else{
                    cout<<"Your user name and password don't match"<<endl;
                    continue;
                }
        }

    if(editedCars == true || editedWorkers == true)
    {
      cout<<"You have unsaved data. Do you want to save now? (Y/N): ";
      string choice;
      cin>>choice;
      if(choice == "Y")
      {
        if(editedWorkers == true)
          workerDatabase.store_workers();

        //if(editedCars == true)

      }      
    }

    cout<<"Godbye..."<<endl;
    return 0;
}


int admin_login(){
    int login;
    cout<<"----------------------"<<endl;
    cout<<"1 -> Add a new car"<<endl;
    cout<<"2 -> Preview car database"<<endl;
    cout<<"3 -> Add a new worker"<<endl;
    cout<<"4 -> Preview worker database"<<endl;
    cout<<"5 -> Search database for car"<<endl;
    cout<<"0 -> Quit"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"-> ";
    cin>>login;
    cin.ignore();
    return login;
}
int worker_login(){
    int login;
    cout<<"----------------------"<<endl;
    cout<<"1 -> Preview car database"<<endl;
    cout<<"2 -> Search database for car"<<endl;
    cout<<"3 -> Sell car"<<endl;
    cout<<"0 -> Quit"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"-> ";
    cin>>login;
    cin.ignore();
    return login;
    
}
