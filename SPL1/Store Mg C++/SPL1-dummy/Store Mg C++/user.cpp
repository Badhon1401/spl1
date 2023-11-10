#include<bits/stdc++.h>
using namespace std;

class User {
public:
    string name;
    double balance;
    User(string n, double b){
        name=n;
        balance=b;
    }

    string getName() const {
        return name;
    }
    double getBalance() const {
        return balance;
    }
    void deposit(double amount){
        balance+=amount;
    }
};