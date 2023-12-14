#include<bits/stdc++.h>
using namespace std;

class User {
    string id;
    string name;
    string password;
    double balance;
    double totalPurchases;
    public:
    User(){}
    User(string b,string n, string p){
        id=b;
        name=n;
        password=p;
        balance=0.0;
        totalPurchases=0.0;
    }

    User(string b,string n, string p,double bal,double t){
        id=b;
        name=n;
        password=p;
        balance=bal;
        totalPurchases=t;
    }

    string getName() const {
        return name;
    }
    string getID() const {
        return id;
    }
    string getPassword() const {
        return password;
    }
    double getBalance() const {
        return balance;
    }
    void depositsMoney(double b){
        balance=balance+b;
    }
    void withDrawMoney(double b){
        balance=balance-b;
    }
    double getTotalPurchases() const {
        return totalPurchases;
    }
    void depositPurchaseAmount(double b){
       totalPurchases=totalPurchases+b;
    }
    int changeName(string a,string b,string c,string nam){
            if(name==a && id==b && password==c){
            name=nam;
            return 1;
        }
        else{
            cout<<"Can not change the password...\n";
            cin.get();
            return 0;
        }
    }
    int  changePassword(string a,string b,string c,string pas){
        if(name==a && id==b && password==c){
            password=pas;
            return 1;
        }
        else{
            cout<<"Can not change the password...\n";
            cin.get();
            return 0;
        }
    }
};