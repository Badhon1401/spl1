#include<bits/stdc++.h>
#include "user.cpp"
using namespace std;

void writeUserToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.name << " " << user.id << endl;
        outFile.close();
        cout << "User data written to file successfully." << endl;
        cin.get();
    } else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
    outFile.close();
}
void writeAllUserToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.name << " " << user.id << endl;
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
        while (inFile >> name >> id) {
            User user(name, id);
            users.push_back(user);
        }
        inFile.close();
    }
    return users;
}
int searchUser(string nam,string idd){
    ifstream inFile("user.dat");
    if (inFile.is_open()) {
        string name;
        string id;
        while (inFile >> name >> id) {
            if(nam==name && idd==id){
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
    cout << "Enter your name: ";
    cin >> name;
    cout << "\nEnter your ID: ";
    cin >> id;
    vector<User> users = readUsersFromFile();
    for (const auto& user : users) {
        if (user.getName() == name && user.getID()==id) {
            cout << "Welcome, " << user.getName() << "!" << endl;
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
    string id;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your ID: ";
    cin >> id;
     if(searchUser(name,id)==1){
        cout<<"Already user exist...\n";
        cin.get();
    }
    else{
    User newUser(name, id);
    writeUserToFile(newUser);
    }
}

void removeUser(){
   system("cls");	
    int i=0;
     string temp;
     string id;
     vector<User> users= readUsersFromFile();
     vector<User> us;
     cout<<"\n\t\t\t\tDelete User Record";
     cout<<"\n\nEnter the name of the user:";
     cin>>temp;
     cout<<"\nEnter the ID of the user:";
     cin>>id;
     ifstream fin("user.dat",ios::binary);
     for (const auto& user : users) {
        if (user.getName() == temp && user.getID()==id) {
            i++;
		  cout<<"\n\t\tUsers Record deleted\n";
          cout<<"User name: "<<user.getName()<<" User ID: "<<user.getID();
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
        writeAllUserToFile(user);
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