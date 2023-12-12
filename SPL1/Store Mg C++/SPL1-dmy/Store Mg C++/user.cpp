#include<bits/stdc++.h>
using namespace std;

class User {
    string id;
    string name;
    string password;
    double points;
    double totalPurchases;
    public:
    User(){}
    User(string b,string n, string p){
        id=b;
        name=n;
        password=p;
        points=0.0;
        totalPurchases=0.0;
    }

    User(string b,string n, string p,double po,double t){
        id=b;
        name=n;
        password=p;
        points=po;
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
    double getPoints() const {
        return points;
    }
    void depositPoints(double b){
        points=points+b;
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