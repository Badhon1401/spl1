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


void displayUsers() {
    vector<User> users = readUsersFromFile();

    if (users.empty()) {
        cout << "No users found.\n";
        cin.get();
        cin.get();
        return;
    }

    int i = 1;

for (const auto& user : users) {
    cout <<i<< ". ID : "<< user.getID()<<" ,  Name : "<< user.getName()<< "\n";
    i++;
}
 cout << "\n";
    cin.get();
}

void detailsOfAllUsers(){
     vector<User> users= readUsersFromFile();
     const int columnCount = 5;  
    int columnWidths[columnCount] = {4, 15, 15, 10, 18};

    cout << "====================================================================\n";
    cout << setw(columnWidths[0]) << "No" << setw(columnWidths[1]) << "ID"
         << setw(columnWidths[2]) << "Name" << setw(columnWidths[3]) << "Balance"
         << setw(columnWidths[4]) << "Total Purchases" << "\n";
    cout << "====================================================================\n";

    int i = 1;

    for (int col = 0; col < columnCount; ++col) {
        cout << string(columnWidths[col], '=') << " ";
    }
    cout << "\n";

    for (const auto& user : users) {
        cout << setw(columnWidths[0]) << i << setw(columnWidths[1]) << user.getID()
             << setw(columnWidths[2]) << user.getName() << setw(columnWidths[3])
             << fixed << setprecision(2) << user.getBalance() << setw(columnWidths[4])
             << fixed << setprecision(2) << user.getTotalPurchases() << "\n";
        i++;
    }

    for (int col = 0; col < columnCount; ++col) {
        cout << string(columnWidths[col], '=') << " ";
    }
    cout << "\n";
    cin.get();
   
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
    
   int i = 1;

for (const auto& user : users) {
    cout <<i<< ". ID : "<< user.getID()<<" ,  Name : "<< user.getName()<< " , Total Purchases : "<< user.getTotalPurchases()<<"\n";
    i++;
}
    cout << "\n";
    cin.get();
}

void searchUser() {
    string userId, name;

    cout << "Enter User ID: ";
    cin >> userId;

    if (user_id_Trie.search(userId) == true) {
         cout << "Enter User Name: ";
    cin >> name;

        if (user_data_Trie.search(userId + name) == true) { 
                cout << "User Found!\n";
                cout << "ID: " << userId << "\n";
                cout << "Name: " << name << "\n";
        
            }
        else {
        cout << "User with this ID and Name combination does not exist.\n";
        cin.get();
        return;
    }

    } else {
        cout << "User with this ID does not exist.\n";
        cin.get();
        return;
    }
    cin.get();
}


void findUserWithMaxTotalPurchases() {
    vector<User> users=readUsersFromFile();
    if (users.empty()) {
        cout << "No users found.\n";
        cin.get();
        return;
    }

    auto maxUser = max_element(users.begin(), users.end(),
        [](const User& user1, const User& user2) {
            return user1.getTotalPurchases() < user2.getTotalPurchases();
        });

    cout << "User with Maximum Total Purchases:\n\n";
    cout << "ID: " << maxUser->getID() << "\n";
    cout << "Name: " << maxUser->getName() << "\n";
    cout << "Total Purchases: " << maxUser->getTotalPurchases() << "\n";

    cin.get();
}

void calculateAverageTotalPurchases() {
    vector<User> users=readUsersFromFile();
    if (users.empty()) {
        cout << "No users found.\n";
        cin.get();
        return;
    }

    double totalPurchasesSum = accumulate(users.begin(), users.end(), 0.0,
        [](double sum, const User& user) {
            return sum + user.getTotalPurchases();
        });


    double averageTotalPurchases = totalPurchasesSum / users.size();

    cout << "Average Total Purchases: " << averageTotalPurchases << "\n";
    cin.get();
}