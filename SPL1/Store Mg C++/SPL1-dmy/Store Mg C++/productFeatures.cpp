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

    cout << "====================================================================\n";
   cout << "                       Sales report                                 \n";
     cout << "====================================================================\n";
    cout << setw(5) << "Serial No" << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "No of Sells \n";
    cout << "====================================================================\n";

    int i = 1;
    for (const auto& product : products) {
        cout << setw(5) << i << setw(10) << product.getID() << setw(20) << product.getName()
             << setw(15) << fixed << setprecision(2) << product.getNoOfSells() << "\n";
        i++;
    }

   cout << "====================================================================\n";
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

void printProductsBasedOnRating(const vector<Product>& products) {
    cout << "Products with details (Serial No, ID, Name, Rating):\n\n";
     cout << "====================================================================\n";
    cout << setw(4) << "Serial No" << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Rating \n";
    cout << "====================================================================\n";

    int i = 1;
    for (const auto& product : products) {
        cout << setw(4) << i << setw(10) << product.getID() << setw(10) << product.getName()
             << setw(10) << fixed << setprecision(2) << product.getRating() << "\n";
        i++;
    }

   cout << "====================================================================\n";
   cin.get();
}

void printProductsBasedOnBuyers(const vector<Product>& products) {
    cout << "Products with details (Serial No, ID, Name, No of Buyers):\n\n";
     cout << "====================================================================\n";
    cout << setw(4) << "Serial No" << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "No of Buyers \n";
    cout << "====================================================================\n";

    int i = 1;
    for (const auto& product : products) {
        cout << setw(4) << i << setw(10) << product.getID() << setw(10) << product.getName()
             << setw(10) << fixed << setprecision(2) << product.getNoOfBuyers() << "\n";
        i++;
    }

   cout << "====================================================================\n";
   cin.get();
}

void printProductsBasedOnSoldCopies(const vector<Product>& products) {
    cout << "Products with details (Serial No, ID, Name, No of Copies Sold):\n\n";
     cout << "====================================================================\n";
    cout << setw(4) << "Serial No" << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "No of Sells \n";
    cout << "====================================================================\n";

    int i = 1;
    for (const auto& product : products) {
        cout << setw(4) << i << setw(10) << product.getID() << setw(10) << product.getName()
             << setw(10) << fixed << setprecision(2) << product.getNoOfSells() << "\n";
        i++;
    }

   cout << "====================================================================\n";
   cin.get();
}


bool compareByRating(const Product& a, const Product& b) {
    return a.getRating() > b.getRating();
}

bool compareByBuyers(const Product& a, const Product& b) {
    return a.getNoOfBuyers() > b.getNoOfBuyers();
}

bool compareBySoldCopies(const Product& a, const Product& b) {
    return a.getNoOfSells() > b.getNoOfSells();
}

void productsByRating(const vector<Product>& products) {
    vector<Product> sortedProducts = products;
    sort(sortedProducts.begin(), sortedProducts.end(), compareByRating);
    cin.get();
    printProductsBasedOnRating(sortedProducts);
}

void productsByBuyers(const vector<Product>& products) {
    vector<Product> sortedProducts = products;
    sort(sortedProducts.begin(), sortedProducts.end(), compareByBuyers);
    cin.get();
   printProductsBasedOnBuyers(sortedProducts);
}

void productsBySoldCopies(const vector<Product>& products) {
    vector<Product> sortedProducts = products;
    sort(sortedProducts.begin(), sortedProducts.end(), compareBySoldCopies);
    cin.get();
    printProductsBasedOnSoldCopies(sortedProducts);
    cin.get();
}

void doRating() {
    string file_name = getFileName();
    vector<Product> products = readProductsFromFile(file_name);

    if (products.empty()) {
        cout << "No products found in the given category.\n";
        cin.get();
        return;
    }
    string id;
    string name;
    cout << "Enter the product ID: ";
    cin >> id;

    cout << "Enter the product name: ";
    cin>>name;
    string code=getGenre(file_name);
    if(product_Trie.search(code+id)){
    bool productFound = false;

    for (auto& product : products) {
        if (product.getID() == id && product.getName() == name) {
            productFound = true;
            cout << "\nExisting Details:\n";
            cout << "ID: " << product.getID() << "\nName: " << product.getName()
                 << "\nRating: " << product.getRating() << "\n";
                 cin.get();
                 float rate;
   while(1){
     cout << "Enter Rating: ";
      rate=getNumericInput();
            if(rate<0.0 || rate>10.0){
                cout<<"Invalid Quantity! It has to be in between 0-10 \n";
                cin.get();
            }
            else{
                product.setRating(rate);           
                break;
            }
    }
            cout << "\nUpdated Details:\n";
            cout << "ID: " << product.getID() << "\nName: " << product.getName()
                 << "\nRating: " << product.getRating() << "\n";

            writeAllProductsToFile(products, file_name);
            break;
        }
    }

    if (!productFound) {
        cout << "Product not found in the given category.\n";
        cin.get();
    }

    cin.get();
    }
    else{
        cout<<"Product with this id and name not found...\n";
        cin.get();
        cin.get();
    }
}
