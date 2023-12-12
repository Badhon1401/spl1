#include<bits/stdc++.h>
#include "userFeatures.cpp"
using namespace std;

void writeNewProductToFile(const Product& product,string file_name) {
     string code=getGenre(file_name);
    ofstream outFile(file_name, ios::app);

    if (outFile.is_open()) {
        outFile << product.getID() << " " <<product.getName()<< " "
                << product.getPrice() << " " << product.getQuantity() << " "
                << product.getNoOfBuyers() << " " << product.getDiscount() << " "
                << product.getRating() << " " << product.getNoOfBuyers() << " "
                << product.getNoOfRaters() << " " << product.getTotalRatingPoints() << endl;

        outFile.close();
        cout << "Product data written to file successfully." << endl;
        product_Trie.insert(code+product.getID());
        cin.get();
        cin.get();
    } else {
        cout << "Unable to open file." << endl;
        cin.get();
    }
}

void writeAllProductsToFile(const vector<Product>& products, const string& file_name) {
    ofstream outFile(file_name);

    if (outFile.is_open()) {
        for (const Product& product : products) {
            outFile << product.getID()<< " " << product.getName() << " "
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
    string id;
    string name;
    float price;
    int quantity;
     int sold;
    float discount;
    float rating;
    int noOfBuyers;
    int totalNoOfRaters;
    double totalRatingPoints;

        while (inFile >> id >> name >> price >> quantity >> sold >> discount >> rating >> noOfBuyers >> totalNoOfRaters >> totalRatingPoints) {
            Product product(id,name,price,quantity,sold,discount,rating,noOfBuyers,totalNoOfRaters,totalRatingPoints);
            products.push_back(product);
        }
        inFile.close();
    }
    return products;
}

void displayProducts() {
    string file_name = getFileName();
    vector<Product> products = readProductsFromFile(file_name);

    if (products.empty()) {
        cout << "The inventory is empty.\n";
        cin.get();
        return;
    }

    cout << "====================================================================\n";
    cout << setw(4) << "Serial No" << setw(15) << "ID" << setw(10) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << "\n";
    cout << "====================================================================\n";

    int i = 1;
    for (const auto& product : products) {
        cout << setw(4) << i << setw(15) << product.getID() << setw(10) << product.getName()
             << setw(15) << fixed << setprecision(2) << product.getPrice() << setw(15) << product.getQuantity() << "\n";
        i++;
    }

   cout << "====================================================================\n";
    cin.get();
}

void detailsOfAllProducts(){
    string file_name=getFileName();
     vector<Product> products= readProductsFromFile(file_name);
     cout<<"So here is the full details of all  product...\n";
     int i=1;
       for (const auto& product : products) {
        cout<<i<<". ID: "<<product.getID()<<" , Name: "<<product.getName()<<" , Price: "<<product.getPrice()<<" , Quantity: "<<product.getQuantity()<<" , Sold: "<<product.getNoOfSells()<<" , Discount: "<<product.getDiscount()<<" , Rating: "<<product.getRating()<<" , Toatal Buyers: "<<product.getNoOfBuyers()<<" , Toatl Raters: "<<product.getNoOfRaters()<<" , Total Rating Points: "<<product.getTotalRatingPoints()<<endl;
       i++;
       }
    cin.get();
    cin.get();
}

void salesReport() {
    string file_name = getFileName();
    system("cls");
    vector<Product> products = readProductsFromFile(file_name);

    cout << "Sales Report:\n";

    // Filter products with positive sales
    vector<Product> soldProducts;
    for (const auto& product : products) {
        if (product.getNoOfSells() > 0) {
            soldProducts.push_back(product);
        }
    }

    if (soldProducts.empty()) {
        cout << "No products with positive sales found." << endl;
        cin.get();
        return;
    }

    // Print header with border lines
    cout << "+" << string(50, '=') << "+\n";
    cout << "|" << setw(4) << "Serial No" << "|" << setw(20) << "ID" << "|" << setw(20) << "Name" << "|" << setw(15) << "Copies Sold" << "|\n";
    cout << "+" << string(50, '=') << "+\n";

    int i = 1;

    for (const auto& product : soldProducts) {
        // Print product details with border lines
        cout << "|" << setw(5) << i << "|" << setw(20) << product.getID() << "|" << setw(20) << product.getName()
             << "|" << setw(15) << product.getNoOfSells() << "|\n";
        i++;
    }

    // Print footer with border lines
    cout << "+" << string(50, '=') << "+\n";

    cin.get();
}


void populate_Product_Trie_With_ProductData() {
    for (int i = 1; i <= 7; ++i) {
        string fileName;
      
        switch (i) {
            case 1:
                fileName = "grocery.dat";
                break;
            case 2:
                fileName = "food&bevarage.dat";
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
        }
         string code=getGenre(fileName);
        
        vector<Product> products = readProductsFromFile(fileName);

        for (const auto& product : products) {
            product_Trie.insert(code+product.getID());
        }
    }

}