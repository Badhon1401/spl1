#include<bits/stdc++.h>
#include "user.cpp"
#include "generalFeatures.cpp"
using namespace std;

void writeNewUserToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.getID() << " " << user.getName() << " " << user.getPassword() <<" " << user.getBalance() <<" " << user.getTotalPurchases() << endl;
        outFile.close();
        cout << "User data written to file successfully." << endl;
        user_id_Trie.insert(user.getID());
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
        outFile << user.getID() << " " << user.getName() << " " << user.getPassword() <<" " << user.getBalance() <<" " << user.getTotalPurchases() << endl;
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

bool signIn(User& us) {
    string id;
    string name;
    string pas;
     cout << "\nEnter your ID: ";
        cin >> id;
    if(user_id_Trie.search(id)==true){
        cout << "\nEnter your Name: ";
        cin >> name;
        if(user_data_Trie.search(id+name)==true){
            cout << "\nEnter your Password: ";
            cin >> pas;
            vector<User> users = readUsersFromFile();
            for (const auto& user : users) {
                if (user.getName() == name && user.getID()==id && user.getPassword()==pas) {
                    us=user;
                    cout << "Welcome, " << user.getName() << "!" << endl;
                        cin.get();
                        cin.get();
                        return true;
        }
    }

    cout << "Password did not match..." << endl;
    cin.get();
    cin.get();
    return false;
    }
    else{
        cout << "Account with this ID and Name not found. Please sign up." << endl;
        cin.get();
        cin.get();
        return false;
    }
    }
    else{
    cout << "Account with this ID not found. Please sign up." << endl;
    cin.get();
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
            if(user_id_Trie.search(id)==1){
                cout<<"This id is already in used please use a separate one...\n";          
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
     user_id_Trie.insert(id);
     user_data_Trie.insert(id+name);
    writeNewUserToFile(newUser);
    
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
    cout << setw(4) << "No." << setw(10) << "ID" << setw(10) << "NAME" << "\n";
    cout << "=====================================\n";

    int i = 1;
    for (const auto& user : users) {
        cout << setw(4) << i << setw(10) << user.getID() << setw(10) << user.getName() << "\n";
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
        cout<<i<<". ID: "<<user.getID()<<", Name: "<<user.getName()<<", Password: "<<user.getPassword()<<", Balance: "<<user.getBalance()<<", Total Purchases: "<<user.getTotalPurchases()<<"\n";
        i++;
        }
    cin.get();
    cin.get();
}

void deleteAccount(User& currentUser) {
    system("cls");
    string temp;
    string id;
    string pass;
    vector<User> users = readUsersFromFile();
    cout << "\n\t\t\tDelete Account";
    cout << "\n\nEnter your ID: ";
    cin >> id;
    if (id==currentUser.getID()) {
        cout << "\nEnter your name: ";
        cin >> temp;
        if (temp==currentUser.getName()) {
            cout << "\nEnter your Password: ";
            cin >> pass;
            if(pass==currentUser.getPassword()){
            auto it = users.begin();
            while (it != users.end()) {
                if (it->getName() == temp && it->getID() == id && it->getPassword() == pass) {
                    cout << "\n\t\tAccount deleted\n";
                    cout << "Account ID: " << it->getID() << "\nAccount Name: " << it->getName() << "\nAccount Password: " << it->getPassword();
                    user_id_Trie.remove(id);
                    user_data_Trie.remove(id + temp);
                    it = users.erase(it);  
                    cin.get();
                    break;
                } else {
                    ++it;
                }
            }
            writeAllUsersToFile(users);
            cin.get();
            }
            else{
                 cout << "Your entered Password is wrong. You have to enter correct user information to delete the account...\n";
                cin.get();
                cin.get();
            }
        } else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
}

void removeUser() {
    system("cls");
    string temp;
    string id;
    string pass;
    vector<User> users = readUsersFromFile();
    cout << "\n\t\t\tDelete User";
    cout << "\n\nEnter User ID: ";
    cin >> id;
    if (user_id_Trie.search(id) == true) {
        cout << "\nEnter User name: ";
        cin >> temp;
        if (user_data_Trie.search(id + temp) == true) {
            auto it = users.begin();
            while (it != users.end()) {
                if (it->getName() == temp && it->getID() == id ) {
                    cout << "\n\t\tUser Record deleted\n";
                    cout << "User ID: " << it->getID() << "\nUser Name: " << it->getName();
                    user_id_Trie.remove(id);
                    user_data_Trie.remove(id + temp);
                    it = users.erase(it);  
                    cin.get();
                    break;
                } else {
                    ++it;
                }
            }
            writeAllUsersToFile(users);
            cin.get();
        }
        else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
            cin.get();
        }
    }
     else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
}
void changeAccountName(User& currentUser){
    system("cls");
    string old_name;
    string id;
    string password;
    vector<User> users= readUsersFromFile();

     cout<<"\n\nEnter your ID: ";
     cin>>id;
     if(id==currentUser.getID()){
     cout<<"\nEnter your old name: ";
     cin>>old_name;
     if(old_name==currentUser.getName()){
     cout<<"\nEnter your password: ";
     cin>>password;
    if(password==currentUser.getPassword()){
     ifstream fin("user.dat",ios::binary);
     for (auto& user : users) {
        if (user.getID()==id && user.getName() == old_name && user.getPassword()==password) {
            string new_name;
            cout<<"\n\nEnter your new name: ";
            cin>>new_name;
            if(user.changeName(old_name,id,password,new_name)){
		  cout<<"\n\t\tAccount Updated\n";
          cout<<"Account ID: "<<user.getID()<<"\nAccount Name: "<<user.getName()<<"\nAccount Password: "<<user.getPassword();
          cin.get();
          currentUser.setName(new_name);
          user_data_Trie.remove(id+old_name);
          user_data_Trie.insert(id+new_name);
          break;
            }
	    }
    }
    fin.close();
     writeAllUsersToFile(users);  
	 cin.get();
    }

       else{
                 cout << "Your entered Password is wrong. You have to enter correct user information to delete the account...\n";
                cin.get();
                cin.get();
            }
        } else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
}

void changeAccountPassword(User& currentUser){
    system("cls");
    string name;
    string id;
    string password;
    vector<User> users= readUsersFromFile();

     cout<<"\n\nEnter your ID: ";
     cin>>id;
     if(id==currentUser.getID()){
     cout<<"\nEnter your name: ";
     cin>>name;
     if(name==currentUser.getName()){
     cout<<"\nEnter your old password: ";
     cin>>password;
   if(password==currentUser.getPassword()){
     ifstream fin("user.dat",ios::binary);
     for (auto& user : users) {
        if (user.getID()==id && user.getName() == name && user.getPassword()==password) {
            string new_password;
            cout<<"\n\nEnter your new password: ";
            cin>>new_password;
            if(user.changePassword(name,id,password,new_password)){
		  cout<<"\n\t\tAccount Updated\n";
          cout<<"Account ID: "<<user.getID()<<"\nAccount Name: "<<user.getName()<<"\nAccount Password: "<<user.getPassword();
          cin.get();
          break;
            }
	    }
    }
    fin.close();
     writeAllUsersToFile(users);  
      }
      
       else{
                 cout << "Your entered Password is wrong. You have to enter correct user information to delete the account...\n";
                cin.get();
                cin.get();
            }
        } else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
}

void populate_User_Trie_With_UserData() {
    vector<User> users = readUsersFromFile();
    for (const auto& user : users) {
        user_id_Trie.insert(user.getID());
        user_data_Trie.insert(user.getID()+user.getName());
    }
}

bool compareUsersByTotalPurchases(const User& user1, const User& user2) {
    return user1.getTotalPurchases() > user2.getTotalPurchases();
}

void printUsersByTotalPurchases() {
    vector<User> users = readUsersFromFile();

    if (users.empty()) {
        cout << "No users found.\n";
        cin.get();
        return;
    }

    sort(users.begin(), users.end(), compareUsersByTotalPurchases);

    cout << "=============================================\n";
    cout << setw(4) << "No." << setw(10) << "ID" << setw(10) << "NAME" << setw(10) << "Total Purchases" << "\n";
    cout << "=============================================\n";

    int i = 1;
    for (const auto& user : users) {
        cout << setw(4) << i << setw(10) << user.getID() << setw(10) << user.getName() << setw(10) << user.getTotalPurchases() << "\n";
        i++;
    }

    cout << "=============================================\n";
    cin.get();
}

void depositMoney(User& us) {

    double depositAmount;
    cout << "Enter the amount you want to deposit: ";
   depositAmount=getPositiveNumericInput();
    vector<User> users = readUsersFromFile();
    for (auto& u : users) {
        if (u.getID() == us.getID()) {
            u.depositsMoney(depositAmount);
            us=u;
            break;
        }
    }
    writeAllUsersToFile(users);

    cout << "Deposit successful! Your new balance is: " << us.getBalance() << endl;
    cin.get(); 
    
}
