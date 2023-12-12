#include<bits/stdc++.h>
#include "user.cpp"
#include "generalFeatures.cpp"
using namespace std;

void writeNewUserToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.getID() << " " << user.getName() << " " << user.getPassword() <<" " << user.getPoints() <<" " << user.getTotalPurchases() << endl;
        outFile.close();
        cout << "User data written to file successfully." << endl;
        user_Trie.insert(user.getID());
        cin.get();
    } 
    else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
    outFile.close();
}

void writeAllUsersToFile(const vector<User>& users) {
    ofstream outFile("user.dat");
    
    if (!outFile.is_open()) {
        cout << "Unable to open file." << endl;
        cin.get();
        return;
    }

    for (const User& user : users) {
        outFile << user.getID() << " " << user.getName() << " " << user.getPassword() <<" " << user.getPoints() <<" " << user.getTotalPurchases() << endl;
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
        double points;
        double totalPurchases;
        while (inFile >> id >> name >> pass >> points >> totalPurchases) {
            User user(id,name,pass,points,totalPurchases);
            users.push_back(user);
        }
        inFile.close();
    }
    return users;
}

bool signIn() {
    string name;
    string id;
    string pas;

    cout << "\nEnter your ID: ";
     cin >> id;
    cout << "\nEnter your name: ";
    cin >> name;

    if(user_Trie.search(id)==true){
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
    else{
    cout << "Account with this ID not found. Please sign up." << endl;
    cin.get();
    return false;
    }
}

void signUp() {
    string name;
    string id;
    string pass;
     while(true){
    cout << "Enter your ID: ";
    cin >> id;
            if(user_Trie.search(id)==1){
                cout<<"This id is already in used please use a separate one...\n";
                cin.get();
                cin.get();            
            }
            else{
               break; 
            }
    }
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your Password: ";
    cin >> pass;
    User newUser(id,name,pass);
    writeNewUserToFile(newUser);
    
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
     cout<<"\n\nEnter the ID of the user: ";
     cin>>id;
     cout<<"\nEnter the name of the user: ";
     cin>>temp;
     if(user_Trie.search(id)==true){
     ifstream fin("user.dat",ios::binary);
     for (const auto& user : users) {
        if (user.getName() == temp && user.getID()==id) {
            i++;
		  cout<<"\n\t\tUser Record deleted\n";
          cout<<"User name: "<<user.getName()<<"\nUser ID: "<<user.getID();
          user_Trie.remove(temp+id);
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
     
        writeAllUsersToFile(us);
     
	 cin.get();
     }
      else{
    cout << "Account with this ID not found. Please sign up." << endl;
    cin.get();
    }
     
}

void displayUsers() {
    vector<User> users = readUsersFromFile();

    if (users.empty()) {
        cout << "No users found.\n";
        cin.get();
        cin.get();
        return;
    }

    cout << "=====================================\n";
    cout << setw(5) << "No." << setw(10) << "ID" << setw(20) << "NAME" << "\n";
    cout << "=====================================\n";

    int i = 1;
    for (const auto& user : users) {
        cout << setw(5) << i << setw(10) << user.getID() << setw(20) << user.getName() << "\n";
        i++;
    }

    cout << "=====================================\n";
    cin.get();
}

void detailsOfAllUsers(){
     vector<User> users= readUsersFromFile();
     cout<<"So here is the deatils all users...\n";
     int i=1;
       for (const auto& user : users) {
        cout<<i<<". ID: "<<user.getID()<<", Name: "<<user.getName()<<", Password: "<<user.getPassword()<<", Point: "<<user.getPoints()<<", Total Purchases: "<<user.getTotalPurchases()<<"\n";
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
     cout<<"\n\nEnter your ID: ";
     cin>>id;
     if(user_Trie.search(id)==true){
         cout<<"\nEnter your name: ";
        cin>>temp;
     cout<<"\nEnter your Password: ";
     cin>>pass;
     ifstream fin("user.dat",ios::binary);
     for (const auto& user : users) {
        if (user.getName() == temp && user.getID()==id && user.getPassword()==pass) {
            i++;
		  cout<<"\n\t\tAccount deleted\n";
          cout<<"Account ID: "<<user.getID()<<"\nAccount Name: "<<user.getName()<<"\nAccount Password: "<<user.getPassword();
          user_Trie.remove(id);
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
     
        writeAllUsersToFile(us);
     
	 cin.get();
}
     else{
        cout<<"Account with this id is not found...\n";
        cin.get();
     }
}

void changeAccountName(){
   system("cls");
     int i=0;	
     string temp;
     string id;
     string pass;
     vector<User> users= readUsersFromFile();
     vector<User> us;

     cout<<"\n\nEnter your ID: ";
     cin>>id;
     if(user_Trie.search(id)==true){
     cout<<"\nEnter your name: ";
     cin>>temp;
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
          cout<<"Account ID: "<<user.getID()<<"\nAccount Name: "<<user.getName()<<"\nAccount Password: "<<user.getPassword();
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
        writeAllUsersToFile(us);
     
	 cin.get();
}
     else{
        cout<<"Account with this id is not found...\n";
        cin.get();
     }
}

void changeAccountPassword(){
   system("cls");
     int i=0;	
     string temp;
     string id;
     string pass;
     vector<User> users= readUsersFromFile();
     vector<User> us;

     cout<<"\n\nEnter your ID: ";
     cin>>id;
     if(user_Trie.search(id)==true){
    cout<<"\nEnter your name: ";
     cin>>temp;
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
          cout<<"Account ID: "<<user.getID()<<"\nAccount Name: "<<user.getName()<<"\nAccount Password: "<<user.getPassword();
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
     
        writeAllUsersToFile(us);
   
	 cin.get();
     }
     else{
        cout<<"Account with this id is not found...\n";
        cin.get();
     }
}

void populate_User_Trie_With_UserData() {
    vector<User> users = readUsersFromFile();
    string code;
    for (const auto& user : users) {
        code=user.getID();
        user_Trie.insert(code);
    }
}