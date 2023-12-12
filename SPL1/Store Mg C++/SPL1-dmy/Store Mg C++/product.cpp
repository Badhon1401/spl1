#include<bits/stdc++.h>
using namespace std;

class Product {
    string name;
    string id;
    float price;
    int quantity;
    int sold;
    float discount;
    float rating;
    int noOfBuyers;
    int totalNoOfRaters;
    double totalRatingPoints;

public:
    Product(string n,string i,float p ,int q){
    name=n;
    id=i;
    price=p;
    quantity=q;
    sold = 0;
    discount = 0.0;
    rating = 5.0;
    noOfBuyers = 0;
    totalRatingPoints = 5.0;
    totalNoOfRaters = 1;
    }
    Product(string n,string i,float p ,int q,int a,float b,float c,int d,int e,double f){
    name=n;
    id=i;
    price=p;
    quantity=q;
    sold = a;
    discount = b;
    rating = c;
    noOfBuyers = d;
    totalRatingPoints = e;
    totalNoOfRaters = f;
    }
    //void get(string n,string i,float p ,int q);
    void show();
    void withdraw(int qty);
    int reduce(int qty);
    int refill(int qty);
    int stock_check(string nm,string idd);
    void sales_show();
    int setDiscount(float disc);
    float getDiscount() const;
    float getPrice() const;
    int getQuantity() const;
    float getRating() const;
    int getNoOfBuyers() const;
    int getNoOfSells() const;
     int getNoOfRaters() const;
     double getTotalRatingPoints() const;
    void setRating();
    string getName() const;
    string getID() const;
};

void Product::show() {
    cout << left << setw(20) << name
             << setw(10) << id
             << setw(10) << quantity
             << setw(10) << price
             << setw(10) << discount << endl;
}

void Product::withdraw(int qty) {
        quantity -= qty;
        sold += qty;
        cout << "\n\nStock updated.\n";
    cin.ignore();
    cin.get();
}
int Product::reduce(int qty) {
        if((quantity-qty)>=0 && (qty<1)){
        quantity -= qty;
         cout << "\n\nStock updated.\n";
          cin.get();
          return 1;
        }
        else{
            cout<<"Insufficient ammount to reduce\n";
            cin.get();
            return 0;
        }
}
int Product::refill(int qty) {
    if(qty>0){
    quantity += qty;
    cout << "\n\nStock updated.\n";
    cin.ignore();
    return 1;
    }
    else{
        cout<<"Quantity has to be greater than 0 ";
        cin.get();
        return 0;
    }
}

int Product::stock_check(string nm,string idd) {
    if (name == nm && id==idd) {
        return 1; 
    } else {
        return 0;
    }
}

void Product::sales_show() {
    if (sold > 0) {
        cout << "\n" << name << "\t\t\t" << sold;
    }
}

int Product::setDiscount(float disc) {
    if (disc >= 0 && disc <= 100) {
        discount = disc;
        return 1;
    } else {
        cout << "Invalid discount percentage. Please enter a value between 0 and 100." << endl;
        return 0;
    }
}

float Product::getDiscount() const {
    return discount;
}

float Product::getPrice() const {
    return price * (1 - discount / 100); 
}

int Product::getQuantity() const {
    return quantity;
}

string Product::getName() const {
    return name;
}

string Product::getID() const {
    return id;
}
float Product::getRating() const {
    return rating;
}

int Product::getNoOfBuyers() const {
    return noOfBuyers;
}
int Product::getNoOfRaters() const {
    return totalNoOfRaters;
}

int Product::getNoOfSells() const {
    return sold;
}

double Product::getTotalRatingPoints() const {
    return totalRatingPoints;
}
void Product::setRating() {
    float rate;
   while(1){
     cout << "Enter Rating: ";
        cin >> rate;
        if(rate<0.0 && rate>10.0){
            cout<<"Invalid Quantity! It has to be in between 0-10 \n";
            cin.get();
        }
        else{
           totalRatingPoints=totalRatingPoints+rate;
           totalNoOfRaters=totalNoOfRaters+1;
           rating=totalRatingPoints/totalNoOfRaters;
        }
        }
}