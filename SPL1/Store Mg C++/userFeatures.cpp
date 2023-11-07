#include<bits/stdc++.h>
#include "user.cpp"
using namespace std;

void writeUserToFile(const User& user) {
    ofstream outFile("user.dat", ios::app);
    if (outFile.is_open()) {
        outFile << user.name << " " << user.balance << endl;
        outFile.close();
        cout << "User data written to file successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
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

void signIn() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    vector<User> users = readUsersFromFile();
    for (const auto& user : users) {
        if (user.getName() == name) {
            cout << "Welcome, " << user.getName() << "!" << endl;
            cout << "Your balance: " << user.getBalance() << endl;
            return;
        }
    }

    cout << "User not found. Please sign up." << endl;
}

void signUp() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    double balance;
    cout << "Enter your initial balance: ";
    cin >> balance;

    User newUser(name, balance);
    writeUserToFile(newUser);
}