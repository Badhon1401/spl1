#include<bits/stdc++.h>
using namespace std;

class Product {

    string id;
    string name;
    double price;
    int quantity;
    int sold;
    double discount;
    double rating;
    int noOfBuyers;
    int totalNoOfRaters;
    double totalRatingPoints;

public:

    Product(string i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
        sold = 0;
        discount = 0.0;
        rating = 5.0;
        noOfBuyers = 0;
        totalNoOfRaters = 1;
        totalRatingPoints = 5.0;
    }

    Product(string i, string n, double p, int q, int a, double b, double c, int d, int e, double f) {
        id = i;
        name = n;
        price = p;
        quantity = q;
        sold = a;
        discount = b;
        rating = c;
        noOfBuyers = d;
        totalNoOfRaters = e;
        totalRatingPoints = f;
    }

    void withdraw(int qty);
    void reduce(int qty);
    void refill(int qty);
    void setDiscount(double disc);
    double getDiscount() const;
    double getPrice() const;
    int getQuantity() const;
    double getRating() const;
    int getNoOfBuyers() const;
    int getNoOfSells() const;
    int getNoOfRaters() const;
    double getTotalRatingPoints() const;
    void setRating(double f);
    void setNoOfBuyers();
    void setPrice(double p);
    void setName(string nam);
    string getName() const;
    string getID() const;
};

void Product::withdraw(int qty) {
    if ((quantity - qty) >= 0) {
        quantity -= qty;
        sold += qty;
        cin.get();
    }
    else {
        cout << "Insufficient amount to withdraw\n";
        cin.get();
    }
}

void Product::reduce(int qty) {
        quantity -= qty;
        cout << "\n\nStock updated.\n";
        cin.get();
       
}

void Product::refill(int qty) {
   
        quantity += qty;
        cout << "\n\nStock updated.\n";
        cin.get();
       
}

void Product::setDiscount(double disc) {
        discount = disc;
}

double Product::getDiscount() const {
    return discount;
}

double Product::getPrice() const {
    return price ;
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

double Product::getRating() const {
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

void Product::setNoOfBuyers() {
    noOfBuyers += 1;
}

void Product::setRating(double f) {
    double rate = f;
    totalRatingPoints = totalRatingPoints + rate;
    totalNoOfRaters = totalNoOfRaters + 1;
    rating = totalRatingPoints / totalNoOfRaters;
}

void Product::setPrice(double p) {
    price = p;
}

void Product::setName(string nam) {
    name = nam;
}