#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class User{
    public:
    string username;
    string password;
};


vector<User> fetchuser(const string& filename){
vector<User> users;
ifstream file(filename);
if(file.is_open()){
User user;
while(file>>user.username>>user.password){
users.push_back(user);
}
file.close();
}
return users;
}

void saveuser(const string & filename,const vector<User>& users){
ofstream file(filename);
if(file.is_open()){
    for(const auto& user:users){
        file<<user.username<<" "<<user.password<<endl;
    }
    file.close();
}
}

bool usernameexist(const vector<User> users,const string& username){
    for(const auto& user:users){
        if(username==user.username){
            return true;
        }
    }
    return false;
}

void registerUser( vector<User>& users){
    string username,password;
    cout<<"enter username"<<endl;
    cin>>username;
    if(usernameexist(users,username)){
        cout<<"username already exist.\nPress 2 for login if you want."<<endl;

        return;
    }
    cout<<"enter password"<<endl;
    cin>>password;
    users.push_back({username,password});
    saveuser("username.txt",users);
    cout<<"\nregistration succesfull!!!\n"<<endl;
}

bool authentication(const vector<User>& users,const string& username,const string& password){
    for(const auto& user:users){
        if(user.username==username&&user.password==password){
            return true;
        }
    }
    return false;
}

void loginUser(vector<User>& users){
    string username,password;
    cout<<"enter username"<<endl;
    cin>>username;
    cout<<"enter password"<<endl;
    cin>>password;
    if(authentication(users,username,password)){
        cout<<"\nlogin succesfull!!!!\n"<<endl;
    }
    else{
        cout<<"invalid username or password"<<endl;
    }
}

int main()
{
/*write your code here*/
vector<User> users=fetchuser("username.txt");
int choice;
    cout<<"-----------------------------\n|      User Authentication  |\n|  Options:                 |\n|     1 for register        |\n|     2 for login           |\n|     3 for exit            |\n-----------------------------\nEnter your choice: ";
do{
    cin>>choice;
    switch (choice)
    {
    case 1:registerUser(users);
        break;
    case 2:loginUser(users);
        break;
    case 3:cout<<"exiting....."<<endl;
        break;
    default:
        cout<<"invalid choice "<<endl;
    }
    if(choice!=3)
    cout<<"Enter choice again."<<endl;
}
while(choice!=3);
return 0;
}
//use of const and & with every function parameters
//use of auto !!!! whyyyyyyy
//how did ifstream and ofstream here worked 
