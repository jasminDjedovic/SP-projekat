#include<iostream>
#include<fstream>
#include<string>
#include "worker.h"
#include "treeCarModel.hxx"

using namespace std;

string admin_user_pass="admin";

bool user_check(const string&, const string&, const string&);
void new_worker(const string& );
int admin_login();
int worker_login();

int main(){
    TreeCarModel carDatabase;
    bool log;
    bool main_log=false;
    int admin_log;
    int worker_log;
    while(main_log==false){
             string user;
             string password;
             cout<<"User name: ";
             cin>>user;
             cout<<"Password: ";
             cin>>password;
             if(user==admin_user_pass && password==admin_user_pass){
                carDatabase.loadCars();
                admin_log=-1;
                while(admin_log!=0){
                    switch (admin_log=admin_login()) {
                        case 1:
                            carDatabase.addCar();
                            break;
                        case 2:
                            carDatabase.printCar();
                            break;
                        case 3:
                            new_worker("workers.txt");
                            break;
                        case 0:
                            main_log=true;
                            cout<<"Good bye..."<<endl;
                            break;
                        default:
                            cout<<"Wrong chose!"<<endl;
                            break;
                    }
                }
                }
                else if(user_check(user,password,"workers.txt")==true){
                worker_log=-1;
                while(worker_log!=0){
                    switch (worker_log=worker_login()) {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 0:
                            main_log=true;
                            cout<<"Good bye..."<<endl;
                            break;
                        default:
                            cout<<"Wrong chose!"<<endl;
                            break;
                    }
                }
                }
                else if(user!=admin_user_pass || password!=admin_user_pass){
                    cout<<"You'r user name and password don't match"<<endl;
                    continue;
                }
        }
    
    return 0;
}


bool user_check(const string& user,const string& pass,const string& file_name){
    ifstream file(file_name);
    if(!file){
        cout<<"The file don't exist."<<endl;
        file.close();
    }
    string pars;
    while(getline(file,pars)){
        int user_letters=0;
        int pass_letters=0;
        for(int i=0;pars[i]!='/';++i){
            ++user_letters;
        }
        for(int i=user_letters+1;pars[i]!='/';++i){
            ++pass_letters;
        }
        if(user!=pars.substr(0,user_letters) && pass!=pars.substr(user_letters+1,pass_letters))
            continue;
        else
            return true;
    }
    file.close();
    return false;
}

void new_worker(const string& file_name){
    string user,pass,name,last_name;
    cout<<"Type you'r name: ";
    cin>>name;
    cout<<"Type you'r last name: ";
    cin>>last_name;
    cout<<"Type you'r username: ";
    cin>>user;
    cout<<"Type you'r password: ";
    cin>>pass;
    cin.ignore();
    if(user_check(user,pass,file_name)==false){
        ofstream file(file_name,ofstream::app);
        if(file.is_open()){
            file<<"\n";
            file<<user<<"/"<<pass<<"/"<<name<<"/"<<last_name<<"/";
            cout<<"The new worker is in the database."<<endl;
        }
        else
            cout<<"The file don't exist."<<endl;
    }
    else
        cout<<"Profile with that user or password exist in the database. Sorry"<<endl;
}


int admin_login(){
    int login;
    cout<<"----------------------"<<endl;
    cout<<"1 -> Add a new car"<<endl;
    cout<<"2 -> Preview the database"<<endl;
    cout<<"3 -> Add a new worker"<<endl;
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
    cout<<"1 -> Preview"<<endl;
    cout<<"2 -> Buy"<<endl;
    cout<<"0 -> Quit"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"-> ";
    cin>>login;
    cin.ignore();
    return login;
    
}
