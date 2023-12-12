#include<bits/stdc++.h>
#include "productFeatures.cpp"
using namespace std;

void customerShopping() {
    vector<pair<Product, int>> purchases;
    int continueShopping = 1;

    while (continueShopping == 1) {
        system("cls");
        int i=1;
        while(i!=0){
        displayProducts(); // Assuming you have a function to display available products
        cout<<"If you are done seeing the inventory then enter 0 otherwise enter 1\n";
        cin>>i;
         system("cls");
        }
        cout<<"Now we will ask you about the category of products that you wanna buy\n";
        string file_name=getFileName();
        string productName;
        int quantity;

        cout << "\nEnter product name: ";
        cin >> productName;
        cout << "Enter quantity: ";
        cin >> quantity;

        vector<Product> products = readProductsFromFile(file_name);

        // Find the product in the inventory
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].getName() == productName) {
                if (products[i].getQuantity() >= quantity) {
                    products[i].withdraw(quantity);
                    purchases.push_back(make_pair(products[i], quantity));
                    cout << "Product added to your cart.\n";
                } else {
                    cout << "Insufficient stock for this quantity.\n";
                }
                break;
            }
        }

        cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
        cin >> continueShopping;
        writeAllProductsToFile(products, file_name);

    }

    // Print the receipt
    cout << "\n\n=============================\n";
    cout << "       Payment Receipt\n";
    cout << "=============================\n";
    cout << "Product\t\tQuantity\tPrice\n";
    cout << "---------------------------------\n";
    float totalAmount = 0;
    for (const auto& purchase : purchases) {
        cout << purchase.first.getName() << "\t" << setw(8) << purchase.second << "\t"
             << setw(6) << fixed << setprecision(2) << purchase.first.getPrice() * purchase.second << endl;
        totalAmount += purchase.first.getPrice() * purchase.second;
    }
    cout << "---------------------------------\n";
    cout << "Total Amount with discount:\t" << fixed << setprecision(2) << totalAmount << endl;
    cout << "=============================\n";
    cout << "Thank you for shopping with us!\n";

    
    cin.get();
    cin.get();
}
