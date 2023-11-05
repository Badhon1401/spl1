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
    User(){
        name="";
        balance=0.0;
    }    
    string getName() const {
        return name;
    }
    double getBalance() const {
        return balance;
    }
}us;