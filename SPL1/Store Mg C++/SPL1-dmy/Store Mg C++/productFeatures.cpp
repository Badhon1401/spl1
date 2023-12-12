#include<bits/stdc++.h>
#include "generalFeatures.cpp"
using namespace std;

void writeNewProductToFile(const Product& product,string file_name) {
    ofstream outFile(file_name, ios::app);

    if (outFile.is_open()) {
        outFile << product.getName() << " " << product.getID() << " "
                << product.getPrice() << " " << product.getQuantity() << " "
                << product.getNoOfBuyers() << " " << product.getDiscount() << " "
                << product.getRating() << " " << product.getNoOfBuyers() << " "
                << product.getNoOfRaters() << " " << product.getTotalRatingPoints() << endl;

        outFile.close();
        cout << "Product data written to file successfully." << endl;
        product_Trie.insert(product.getName()+product.getID());
        cin.get();
        cin.get();
    } else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
}

void writeAllProductsToFile(const vector<Product>& products, const string& file_name) {
    ofstream outFile(file_name, ios::app);

    if (outFile.is_open()) {
        for (const Product& product : products) {
            outFile << product.getName() << " " << product.getID() << " "
                    << product.getPrice() << " " << product.getQuantity() << " "
                    << product.getNoOfSells() << " " << product.getDiscount() << " "
                    << product.getRating() << " " << product.getNoOfBuyers() << " "
                    << product.getNoOfRaters() << " " << product.getTotalRatingPoints() << endl;
        }

        outFile.close();
        cout << "Products data written to file successfully." << endl;
        cin.get();
    } else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
}

vector<Product> readProductsFromFile(string file_name) {
    vector<Product> products;
    ifstream inFile(file_name);
    if (inFile.is_open()) {
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

        while (inFile >> name >> id >> price >> quantity >> sold >> discount >> rating >> noOfBuyers >> totalNoOfRaters >> totalRatingPoints) {
            Product product(name,id,price,quantity,sold,discount,rating,noOfBuyers,totalNoOfRaters,totalRatingPoints);
            products.push_back(product);
        }
        inFile.close();
    }
    return products;
}

void displayProducts(){
    string file_name=getFileName();
     vector<Product> products= readProductsFromFile(file_name);
     cout<<"So here is the list of all  product...\n";
     int i=1;
       for (const auto& product : products) {
        cout<<i<<". Name: "<<product.getName()<<" , ID: "<<product.getID()<<" , Price: "<<product.getPrice()<<" , Quantity: "<<product.getQuantity()<<"\n";
        i++;
        }
    cin.get();
}

void detailsOfAllProducts(){
    string file_name=getFileName();
     vector<Product> products= readProductsFromFile(file_name);
     cout<<"So here is the full details of all  product...\n";
     int i=1;
       for (const auto& product : products) {
        cout<<i<<". Name: "<<product.getName()<<" , ID: "<<product.getID()<<" , Price: "<<product.getPrice()<<" , Quantity: "<<product.getQuantity()<<" , Sold: "<<product.getNoOfSells()<<" , Discount: "<<product.getDiscount()<<" , Rating: "<<product.getRating()<<" , Toatal Buyers: "<<product.getNoOfBuyers()<<" , Toatl Raters: "<<product.getNoOfRaters()<<" , Total Rating Points: "<<product.getTotalRatingPoints()<<endl;
       i++;
       }
    cin.get();
    cin.get();
}

void salesReport() {
    string file_name=getFileName();
    system("cls");
    vector<Product> products = readProductsFromFile(file_name);

    cout << "Sales Report:\n";
    int i = 1;
    
    for (const auto& product : products) {
        if (product.getNoOfSells() > 0) {
            cout << i << ". Name: " << product.getName() << " , ID: " << product.getID()
                 << " , Copies Sold: " << product.getNoOfSells() << endl;
            i++;
        }
    }

    if (i == 1) {
        cout << "No products with positive sales found." << endl;
    }

    cin.get();
    cin.get();
}

void populate_Product_Trie_With_ProductData() {
    for (int i = 1; i <= 7; ++i) {
        std::string fileName;
        
        // Switch case to determine the file based on the value of i
        switch (i) {
            case 1:
                fileName = "grocery.dat";
                break;
            case 2:
                fileName = "food&beverage.dat";
                break;
            case 3:
                fileName = "electronics.dat";
                break;
            case 4:
                fileName = "book&stationary.dat";
                break;
            case 5:
                fileName = "fashion&beauty.dat";
                break;
            case 6:
                fileName = "healthcare.dat";
                break;
            case 7:
                fileName = "homeappliance.dat";
                break;
            default:
                std::cerr << "Invalid option.\n";
                return;
        }

        // Read product data from the file
        std::vector<Product> products = readProductsFromFile(fileName);

        // Insert product names and IDs into the Trie
        for (const auto& product : products) {
            std::string code = product.getName() + product.getID();
            product_Trie.insert(code);
        }
    }

}