#include<bits/stdc++.h>
using namespace std;

class User {
public:
    string name;
    string id;
    User(string n, string b){
        name=n;
        id=b;
    }
    string getName() const {
        return name;
    }
    string getID() const {
        return id;
    }
};