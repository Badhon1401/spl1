#include<bits/stdc++.h>
#include "user.cpp"
using namespace std;

void writeUserToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.name << " " << user.balance << endl;
        outFile.close();
        cout << "User data written to file successfully." << endl;
        cin.get();
    } else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
}

vector<User> readUsersFromFile() {
    vector<User> users;
    ifstream inFile("user.dat");
    if (inFile.is_open()) {
        string name;
        double balance;
        while (inFile >> name >> balance) {
            User user(name, balance);
            users.push_back(user);
        }
        inFile.close();
    }
    return users;
}
int searchUser(string nam){
    ifstream inFile("user.dat");
    if (inFile.is_open()) {
        string name;
        double balance;
        while (inFile >> name >> balance) {
            if(nam==name){
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
    cout << "Enter your name: ";
    cin >> name;
    vector<User> users = readUsersFromFile();
    for (const auto& user : users) {
        if (user.getName() == name) {
            cout << "Welcome, " << user.getName() << "!" << endl;
            cout << "Your balance: " << user.getBalance() << endl;
            cin.get();
            return true;
        }
    }

    cout << "User not found. Please sign up." << endl;
    cin.get();
    return false;
}

void signUp() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
     if(searchUser(name)==1){
        cout<<"Already user exist...\n";
        cin.get();
    }
    else{
    double balance;
    cout << "Enter your initial balance: ";
    cin >> balance;

    User newUser(name, balance);
    writeUserToFile(newUser);
    }
}

void removeUser(){
    system("cls");	
    int i=0;
     string temp;
     vector<User> users= readUsersFromFile();
     cout<<"\n\t\t\t\tDelete User Record";
     cout<<"\n\nEnter the name of the user:";
     cin>>temp;
     ofstream fout("temp.dat",ios::binary);
     ifstream fin("user.dat",ios::binary);
     for (const auto& user : users) {
        if (user.getName() == temp) {
            i++;
		  cout<<"\n\n\t\tUsers Record deleted";
          cout<<"User name: "<<user.getName();
          cin.get();
	    }
	    else{
		  fout.write((char*)&user,sizeof(user));
        }
    }
    if(i==0){
        cout<<"Users not found...\n";
        cin.get();
        cin.get();
        return;
    }
     fin.close();
     fout.close();
     remove("user.dat");
     rename("temp.dat","user.dat");
	 cin.get();
}
void listOfUsers(){
     vector<User> users= readUsersFromFile();
     cout<<"So here is the list of all users...\n";
     int i=1;
       for (const auto& user : users) {
        cout<<i<<". "<<user.getName()<<"\n";
        i++;
        }
    cin.get();
    cin.get();
}