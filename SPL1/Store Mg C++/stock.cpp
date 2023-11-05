#include<bits/stdc++.h>
using namespace std;

class Stock {
    string name;
    float price;
    int quantity;
    int sold;
    float discount;

public:
    void get();
    void show();
    void withdraw(int qty);
    void refill(int qty);
    int stock_check(string nm);
    void sales_show();
    void setDiscount(float disc);
    float getDiscount() const;
    float getPrice() const;
    int getQuantity() const;
    string getName() const;
}st;

void Stock::get() {
    cout << "Enter name -> price -> quantity -> discount...\n";
    cin >> name >> price >> quantity >> discount;
    sold = 0;
}

void Stock::show() {
    cout << "\n" << name << "\t\t\t" << quantity << "    " << price << "    " << discount;
}

void Stock::withdraw(int qty) {
        quantity -= qty;
        sold += qty;
        cout << "\n\nStock updated.\n";
    cin.ignore();
    cin.get();
}

void Stock::refill(int qty) {
    quantity += qty;
    cout << "\n\nStock updated.";
    cin.ignore();
    cin.get();
}

int Stock::stock_check(string nm) {
    if (name == nm) {
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