#include<bits/stdc++.h>
#include "userFeatures.cpp"
using namespace std;

void writeNewProductToFile(const Product& product,string file_name) {
    ofstream outFile(file_name, ios::app);

    if (outFile.is_open()) {
        outFile << product.getID() << " " <<product.getName()<< " "
                << product.getPrice() << " " << product.getQuantity() << " "
                << product.getNoOfBuyers() << " " << product.getDiscount() << " "
                << product.getRating() << " " << product.getNoOfBuyers() << " "
                << product.getNoOfRaters() << " " << product.getTotalRatingPoints() << endl;

        outFile.close();
        cout << "Product data written to file successfully." << endl;
        product_id_Trie.insert(product.getID());
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
    double price;
    int quantity;
     int sold;
    double discount;
    double rating;
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

void displayProducts(string file_name) {
    vector<Product> products = readProductsFromFile(file_name);

    if (products.empty()) {
        cout << "The inventory is empty.\n";
        cin.get();
        return;
    }


   int i = 1;

for (const auto& product : products) {
    cout <<i<< ". ID : "<< product.getID()<<" ,  Name : "<< product.getName() << " , Price : " << product.getPrice() <<" , Quantity : "<< product.getQuantity() << "\n";
    i++;
}


}

void displayProducts() {
    string file_name = getFileName();
    vector<Product> products = readProductsFromFile(file_name);

    if (products.empty()) {
        cout << "The inventory is empty.\n";
        cin.get();
        return;
    }

int i = 1;

for (const auto& product : products) {
    cout <<i<< ". ID : "<< product.getID()<<" ,  Name : "<< product.getName() << " , Price : " << product.getPrice() <<" , Quantity : "<< product.getQuantity() << "\n";
    i++;
}

    cin.get();
    cin.get();
}

void detailsOfAllProducts(){
    string file_name=getFileName();
     vector<Product> products= readProductsFromFile(file_name);
     const int columnCount = 11;  
    int columnWidths[columnCount] = {5, 15, 10, 10, 10, 10, 10, 10, 10, 15, 20};

    cout << "============================================================================================================================\n";
    cout << setw(columnWidths[0]) << "No" << setw(columnWidths[1]) << "ID"
         << setw(columnWidths[2]) << "Name" << setw(columnWidths[3]) << "Price"
         << setw(columnWidths[4]) << "Quantity" << setw(columnWidths[5]) << "Sold"
         << setw(columnWidths[6]) << "Discount" << setw(columnWidths[7]) << "Rating"
         << setw(columnWidths[8]) << "Buyers" << setw(columnWidths[9]) << "Raters"
         << setw(columnWidths[10]) << "Rating Points" << "\n";
    cout << "============================================================================================================================\n";

    int i = 1;

    for (const auto& product : products) {
        cout << setw(columnWidths[0]) << i << setw(columnWidths[1]) << product.getID()
             << setw(columnWidths[2]) << product.getName()
             << setw(columnWidths[3]) << fixed << setprecision(2) << product.getPrice()
             << setw(columnWidths[4]) << product.getQuantity()
             << setw(columnWidths[5]) << product.getNoOfSells()
             << setw(columnWidths[6]) << product.getDiscount()
             << setw(columnWidths[7]) << product.getRating()
             << setw(columnWidths[8]) << product.getNoOfBuyers()
             << setw(columnWidths[9]) << product.getNoOfRaters()
             << setw(columnWidths[10]) << product.getTotalRatingPoints() << endl;

        i++;
    }
      cout << "============================================================================================================================\n";
    cin.get();
}

void salesReport() {
    string file_name = getFileName();
    system("cls");
    vector<Product> products = readProductsFromFile(file_name);
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

    int i = 1;

    for (const auto& product : products) {
        cout<< i <<". ID : " << product.getID()
             << " , Name : " << product.getName()
             << " , No of Sells : " << product.getNoOfSells() << "\n";
        i++;
    }
    
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
                fileName = "homeapplaince.dat";
                break;
        }
    
        vector<Product> products = readProductsFromFile(fileName);

        for (const auto& product : products) {
            product_id_Trie.insert(product.getID());
            product_data_Trie.insert(product.getID()+product.getName());
            
        }
    }

}

void printProductsBasedOnRating(const vector<Product>& products) {

    int i=1;

    for (const auto& product : products) {
        cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , Rating : " << product.getRating() << "\n";
        i++;
    }

}

void printProductsBasedOnBuyers(const vector<Product>& products) {
    
    int i=1;

    for (const auto& product : products) {
        cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , No of Buyers : " << product.getNoOfBuyers() << "\n";
        i++;
    }

}

void printProductsBasedOnSoldCopies(const vector<Product>& products) {

  int i=1;

    for (const auto& product : products) {
        cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , No of Sells : " << product.getNoOfSells() << "\n";
        i++;
    }
   
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

const double ratingWeight = 0.4;
const double buyersWeight = 0.4;
const double soldCopiesWeight = 0.2;

bool compareByOverallPerformance(const Product& a, const Product& b) {
    double overallPerformanceA = ratingWeight * a.getRating()
                              + buyersWeight * a.getNoOfBuyers()
                              + soldCopiesWeight * a.getNoOfSells();

    double overallPerformanceB = ratingWeight * b.getRating()
                              + buyersWeight * b.getNoOfBuyers()
                              + soldCopiesWeight * b.getNoOfSells();

    return overallPerformanceA > overallPerformanceB;
}

void productsByOverallPerformance(const vector<Product>& products) {
    vector<Product> sortedProducts = products;
    sort(sortedProducts.begin(), sortedProducts.end(), compareByOverallPerformance);
    cin.get();

int i=1;

    for (const auto& product : products) {
        double overallPerformance = ratingWeight * product.getRating()
                             + buyersWeight * product.getNoOfBuyers()
                             + soldCopiesWeight * product.getNoOfSells();
        cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , Average Performance : " << overallPerformance << "\n";
        i++;
    }

}

void revenueReport() {
    string file_name=getFileName();
    vector<Product> products=readProductsFromFile(file_name);
    double totalRevenue = 0.0;
      int i=1;
cout << "Products with corresponding revinew:\n\n";
    for (const auto& product : products) {
        double productRevenue = product.getPrice() * product.getNoOfSells();
        totalRevenue += productRevenue;
        cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , Revenue : " << productRevenue << "\n";
        i++;
    }
  
   
    cout << "\n\n\t\tTotal Revenue: "<< totalRevenue << "\n";
    
    cin.get();
}

void lowStockProducts() {
    string file_name=getFileName();
    vector<Product> products=readProductsFromFile(file_name);
    int threshold = 10;
    cout << "Products with Low Stock:\n\n";
    
    int i = 1;
    for (const auto& product : products) {
        if (product.getQuantity() < threshold) {
             cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , Remaining Stocks : " << product.getQuantity() << "\n";
        i++;
           
        }
    }

    if (i == 1) {
        cout << "No products with low stock.\n";
    }

    cin.get();
}

void highRatedProducts() {
    string file_name=getFileName();
    vector<Product> products=readProductsFromFile(file_name);
     double ratingThreshold = 6.0;
    cout << "Highly Rated Products:\n\n";

    int i = 1;
    for (const auto& product : products) {
        if (product.getRating() >= ratingThreshold) {
            cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , Rating : " << product.getRating() << "\n";
        i++;
        }
    }

    if (i == 1) {
        cout << "No highly rated products.\n";
    }

    cin.get();
}

void productsWithDiscounts() {
    string file_name=getFileName();
    vector<Product> products=readProductsFromFile(file_name);
    double discountThreshold = 1.5;
    cout << "Products with Discounts:\n\n";

    int i = 1;
    for (const auto& product : products) {
        if (product.getDiscount() > discountThreshold) {
             cout <<i<<". ID : "<< product.getID()
             << " , Name : " << product.getName()
             << " , Discount : " << product.getDiscount() << "\n";
        i++;
        }
    }

    if (i == 1) {
        cout << "No products with discounts.\n";
    }

    cin.get();
}

void topDiscountedProducts(const vector<Product>& products, int numTopProducts = 5) {
    vector<Product> sortedProducts = products;
    sort(sortedProducts.begin(), sortedProducts.end(), [](const Product& a, const Product& b) {
        return a.getDiscount() > b.getDiscount();
    });

    cout << "Top Discounted Products:\n\n";
   

    size_t i = 1;

    for (int  j = 0; j < numTopProducts && j < int(sortedProducts.size()); ++j) {
        cout <<i<<". ID : "<< sortedProducts[j].getID()
             << " , Name : " << sortedProducts[j].getName()
             << " , Discount : " << sortedProducts[j].getDiscount() << "\n";
        i++;
    }

    if (i == 1) {
        cout << "No discount data available.\n";
    }

    cin.get();
}


void totalRevenue() {
    string file_name=getFileName();
    vector<Product> products=readProductsFromFile(file_name);
    double totalRev = 0.0;

    for (const auto& product : products) {
        totalRev += (product.getPrice() * product.getNoOfSells());
    }

    cout << "Total Revenue: " << totalRev << "\n";
    cin.get();
}