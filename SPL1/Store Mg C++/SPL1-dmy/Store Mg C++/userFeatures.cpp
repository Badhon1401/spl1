#include<bits/stdc++.h>
#include "user.cpp"
using namespace std;

void writeUserToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.getName() << " " << user.getID() << " " << user.getPassword() << endl;
        outFile.close();
        cout << "User data written to file successfully." << endl;
        cin.get();
    } else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
    outFile.close();
}
void writeAllUsersToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.getName() << " " << user.getID() << " " << user.getPassword() << endl;
        outFile.close();
    } else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
    outFile.close();
}

vector<User> readUsersFromFile() {
    vector<User> users;
    ifstream inFile("user.dat");
    if (inFile.is_open()) {
        string name;
        string id;
        string pass;
        while (inFile >> name >> id >> pass) {
            User user(name, id, pass);
            users.push_back(user);
        }
        inFile.close();
    }
    return users;
}
int searchUser(string nam,string idd,string password){
    ifstream inFile("user.dat");
    if (inFile.is_open()) {
        string name;
        string id;
        string pass;
        while (inFile >> name >> id >> pass) {
            if(nam==name && idd==id && password==pass){
                 inFile.close();
                 return 1;
            }
        }

    }
    inFile.close();
    return 0;

}

bool signIn() {
    string name;
    string id;
    string pas;
    cout << "Enter your name: ";
    cin >> name;
    cout << "\nEnter your ID: ";
    cin >> id;
    cout << "\nEnter your Password: ";
    cin >> pas;
    vector<User> users = readUsersFromFile();
    for (const auto& user : users) {
        if (user.getName() == name && user.getID()==id && user.getPassword()==pas) {
            cout << "Welcome, " << user.getName() << "!" << endl;
            cin.get();
            return true;
        }
    }

    cout << "Account not found. Please sign up." << endl;
    cin.get();
    return false;
}

void signUp() {
    vector<User> users= readUsersFromFile();
    string name;
    string id;
    string pass;

    cout << "Enter your name: ";
    cin >> name;
    while(1){
    cout << "Enter your ID: ";
    cin >> id;
    int flag=1;
        for (const auto& user : users) {
            if(user.getID()==id){
                cout<<"This id is already in used please use a separate one...\n";
                cin.get();
                cin.get();
                flag=0;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    cout << "Enter your Password: ";
    cin >> pass;
    User newUser(name, id, pass);
    writeUserToFile(newUser);
    
}

void removeUser(){
   system("cls");	
    int i=0;
     string temp;
     string id;
     vector<User> users= readUsersFromFile();
     vector<User> us;
     cout<<"\n\t\t\tDelete User Record";
     cout<<"\n\nEnter the name of the user: ";
     cin>>temp;
     cout<<"\nEnter the ID of the user: ";
     cin>>id;
     ifstream fin("user.dat",ios::binary);
     for (const auto& user : users) {
        if (user.getName() == temp && user.getID()==id) {
            i++;
		  cout<<"\n\t\tUser Record deleted\n";
          cout<<"User name: "<<user.getName()<<"\nUser ID: "<<user.getID();
          cin.get();
	    }
	    else{
          us.push_back(user);
        }
    }
    fin.close();
    remove("user.dat");
    if(i==0){
        cout<<"Users not found...\n";
        cin.get();
    }
     for (const auto& user : us) {
        writeAllUsersToFile(user);
     }
	 cin.get();
}
void listOfUsers(){
     vector<User> users= readUsersFromFile();
     cout<<"So here is the list of all users...\n";
     int i=1;
       for (const auto& user : users) {
        cout<<i<<". Name: "<<user.getName()<<" ID: "<<user.getID()<<"\n";
        i++;
        }
    cin.get();
    cin.get();
}
void deleteAccount(){
   system("cls");	
    int i=0;
     string temp;
     string id;
     string pass;
     vector<User> users= readUsersFromFile();
     vector<User> us;
     cout<<"\n\t\t\tDelete Account";
     cout<<"\n\nEnter your name: ";
     cin>>temp;
     cout<<"\nEnter your ID: ";
     cin>>id;
     cout<<"\nEnter your Password: ";
     cin>>pass;
     ifstream fin("user.dat",ios::binary);
     for (const auto& user : users) {
        if (user.getName() == temp && user.getID()==id && user.getPassword()==pass) {
            i++;
		  cout<<"\n\t\tAccount deleted\n";
          cout<<"Account name: "<<user.getName()<<"\nAccount ID: "<<user.getID()<<"\nAccount Password: "<<user.getPassword();
          cin.get();
	    }
	    else{
          us.push_back(user);
        }
    }
    fin.close();
    remove("user.dat");
    if(i==0){
        cout<<"Account not found...\n";
    }
     for (const auto& user : us) {
        writeAllUsersToFile(user);
     }
	 cin.get();
}

void changeAccountName(){
   system("cls");
     int i=0;	
     string temp;
     string id;
     string pass;
     vector<User> users= readUsersFromFile();
     vector<User> us;

     cout<<"\n\nEnter your name: ";
     cin>>temp;
     cout<<"\nEnter your ID: ";
     cin>>id;
     cout<<"\nEnter your Password: ";
     cin>>pass;

     ifstream fin("user.dat",ios::binary);
     for (auto& user : users) {
        if (user.getName() == temp && user.getID()==id && user.getPassword()==pass) {
            i++;
            string nam;
            cout<<"\n\nEnter your new name: ";
            cin>>nam;
            int b=0;
            b=user.changeName(temp,id,pass,nam);
            if(b==1){
		  cout<<"\n\t\tAccount Updated\n";
          cout<<"Account name: "<<user.getName()<<"\nAccount ID: "<<user.getID()<<"\nAccount Password: "<<user.getPassword();
            }
          us.push_back(user);
          cin.get();
	    }
	    else{
          us.push_back(user);
        }
    }
    fin.close();
    remove("user.dat");
    if(i==0){
        cout<<"Account not found...\n";
    }
     for (const auto& user : us) {
        writeAllUsersToFile(user);
     }
	 cin.get();
}

void changeAccountPassword(){
   system("cls");
     int i=0;	
     string temp;
     string id;
     string pass;
     vector<User> users= readUsersFromFile();
     vector<User> us;

     cout<<"\n\nEnter your name: ";
     cin>>temp;
     cout<<"\nEnter your ID: ";
     cin>>id;
     cout<<"\nEnter your Password: ";
     cin>>pass;

     ifstream fin("user.dat",ios::binary);
     for (auto& user : users) {
        if (user.getName() == temp && user.getID()==id && user.getPassword()==pass) {
            i++;
            int b=0;
            string p;
            cout<<"\n\nEnter your new password: ";
            cin>>p;
            b=user.changePassword(temp,id,pass,p);
            if(b==1){
		  cout<<"\n\t\tAccount Updated\n";
          cout<<"Account name: "<<user.getName()<<"\nAccount ID: "<<user.getID()<<"\nAccount Password: "<<user.getPassword();
            }
          us.push_back(user);
          cin.get();
	    }
	    else{
          us.push_back(user);
        }
    }
    fin.close();
    remove("user.dat");
    if(i==0){
        cout<<"Account not found...\n";
    }
     for (const auto& user : us) {
        writeAllUsersToFile(user);
     }
	 cin.get();
}

