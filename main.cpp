#include<iostream>
#include<fstream>

using namespace std;

bool user_check(string user,string pass,string file_name){
    ifstream file(file_name);
    if(!file){
        cout<<"The file don't exist."<<endl;
        file.close();
    }
    string pars;
    while(getline(file,pars)){
        int user_letters=0;
        int pass_letters=0;
        for(int i=0;pars[i]!='/';++i)
            ++user_letters;
        for(int i=user_letters+1;pars[i]!=' ';++i)
            ++pass_letters;
        if(user!=pars.substr(0,user_letters) || pass!=pars.substr(user_letters+1,pass_letters))
            continue;
        else
            return true;
    }
    file.close();
    return false;
}

void new_worker_admin(string file_name){
    string user,pass;
    cout<<"Type you'r username: ";
    cin>>user;
    cout<<"Type you'r password: ";
    cin>>pass;
    cin.ignore();
    if(user_check(user,pass,file_name)==false){
    ofstream file(file_name,ofstream::app);
    if(file.is_open()){
        file<<user<<"/"<<pass<<"\n";
        cout<<"The new worker is in the database."<<endl;
    }
    else
        cout<<"The file don't exist."<<endl;
    }
    else
        cout<<"Profile with that user or password exist in the database. Sorry"<<endl;
}

int main_login(){
    int login;
    cout<<"----------------------"<<endl;
    cout<<"1 -> Administrator"<<endl;
    cout<<"2 -> Worker"<<endl;
    cout<<"0 -> Quit"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Login: ";
    cin>>login;
    cin.ignore();
    return login;
}

int admin_login(){
    int login;
    cout<<"----------------------"<<endl;
    cout<<"1 -> Add a new car"<<endl;
    cout<<"2 -> Preview the database"<<endl;
    cout<<"3 -> Add a new worker"<<endl;
    cout<<"4 -> Add a new administrator"<<endl;
    cout<<"0 -> Return to the menu"<<endl;
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
    cout<<"0 -> Return to the menu"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"-> ";
    cin>>login;
    cin.ignore();
    return login;
}

int main(){
    bool log;
    int main_log=-1;
    int admin_log;
    int worker_log;
    while(main_log!=0){
        switch (main_log=main_login()) {
            case 1:
                log=false;
                while(log==false){
                string user;
                string password;
                cout<<"User name: ";
                cin>>user;
                cout<<"Password: ";
                cin>>password;
                if(user_check(user,password,"admin.txt")==false)
                    cout<<"You'r user name and password don't match"<<endl;
                
                else{
                log=true;
                admin_log=-1;
                while(admin_log!=0){
                    switch (admin_log=admin_login()) {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            new_worker_admin("worker.txt");
                            break;
                        case 4:
                            new_worker_admin("admin.txt");
                            break;
                        case 0:
                            cout<<"Returning..."<<endl;
                            break;
                        default:
                            cout<<"Wrong chose!"<<endl;
                            break;
                    }
                }
                }
                }
                
                break;
                
            case 2:
                log=false;
                while(log==false){
                    string user;
                    string password;
                    cout<<"User name: ";
                    cin>>user;
                    cout<<"Password: ";
                    cin>>password;
                    if(user_check(user,password,"workers.txt")==false)
                        cout<<"You'r user name and password don't match"<<endl;
                else{
                log=true;
                worker_log=-1;
                while(worker_log!=0){
                    switch (worker_log=worker_login()) {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 0:
                            cout<<"Returning..."<<endl;
                            break;
                        default:
                            cout<<"Wrong chose!"<<endl;
                            break;
                    }
                }
                }
                }
                break;
                
            case 0:
                cout<<"Good bye..."<<endl;
                break;
            default:
                cout<<"Wrong chose!"<<endl;
                break;
        }
    }
    return 0;
}