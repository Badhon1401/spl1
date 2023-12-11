#include<bits/stdc++.h>
using namespace std;

class User {
    string name;
    string id;
    string password;
    double points;
    double totalPurchases;
    public:
    User(string n, string b, string p){
        name=n;
        id=b;
        password=p;
        points=0.0;
        totalPurchases=0.0;
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