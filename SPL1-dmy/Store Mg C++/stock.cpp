#include<bits/stdc++.h>
using namespace std;

class Stock {
    string name;
    float price;
    int quantity;
    string id;
    int sold;
    float discount;
    float rating;
    int noOfBuyers;
    int totalNoOfRaters;
    double totalRatingPoints;


public:
    void get(string n,string i,float p ,int q);
    void show();
    void withdraw(int qty);
    void reduce(int qty);
    void refill(int qty);
    int stock_check(string nm,string idd);
    void sales_show();
    void setDiscount(float disc);
    float getDiscount() const;
    float getPrice() const;
    int getQuantity() const;
    float getRating() const;
    int getNoOfBuyers() const;
    void setRating();
    string getName() const;
    string getID() const;
}st;

void Stock::get(string n,string i,float p,int q) {
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


void Stock::show() {
    cout << left << setw(20) << name
             << setw(10) << id
             << setw(10) << quantity
             << setw(10) << price
             << setw(10) << discount << endl;
}

void Stock::withdraw(int qty) {
        quantity -= qty;
        sold += qty;
        cout << "\n\nStock updated.\n";
    cin.ignore();
    cin.get();
}
void Stock::reduce(int qty) {
        if((quantity-qty)>=0){
        quantity -= qty;
         cout << "\n\nStock updated.\n";
          cin.get();
        }
        else{
            cout<<"Insufficient ammount to reduce\n";
            cin.get();
        }
}
void Stock::refill(int qty) {
    quantity += qty;
    cout << "\n\nStock updated.";
    cin.ignore();
    cin.get();
}

int Stock::stock_check(string nm,string idd) {
    if (name == nm && id==idd) {
        return 1; 
    } else {
        return 0;
    }
}

void Stock::sales_show() {
    if (sold > 0) {
        cout << "\n" << name << "\t\t\t" << sold;
    }
}

void Stock::setDiscount(float disc) {
    discount = disc;
}

float Stock::getDiscount() const {
    return discount;
}

float Stock::getPrice() const {
    return price * (1 - discount / 100); 
}

int Stock::getQuantity() const {
    return quantity;
}

string Stock::getName() const {
    return name;
}

string Stock::getID() const {
    return id;
}
float Stock::getRating() const {
    return rating;
}

int Stock::getNoOfBuyers() const {
    return noOfBuyers;
}
void Stock::setRating() {
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