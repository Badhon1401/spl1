#include<bits/stdc++.h>
#include "customerFeatures.cpp"
using namespace std;

void addNewProduct() {
    string file_name=getFileName();
    int num=0;
    string name;
    string id;
     float price;
    int quantity;
        system("cls");
        cout << "\nEnter the No. of Products that you wish to add: ";
        num=getNumericInput(1,10);

    for(int i=0;i<num;i++){
    system("cls");
    while(true){
    cout << "Enter Product ID: ";
    cin >> id;
            if(product_id_Trie.search(id)==1){
                cout<<"This product id is already in use please use a separate one...\n";
                cin.get();
            }
            else{
                break;
            }
    }
            cout << "Enter Product Name: ";
            cin >> name;           
            cout << "Enter Price: ";
            price=getDoubleNumericInput(0.00001,1000000000.0);
            cout << "Enter quantity: ";
            quantity=getNumericInput(1,1000);

    Product pr(id,name,price,quantity);
    writeNewProductToFile(pr,file_name);
    product_id_Trie.insert(id);
    product_data_Trie.insert(id+name);
    }
    
}

void removeProduct() {
    string file_name = getFileName();
    system("cls");
    string productName;
    string productId;
    vector<Product> products = readProductsFromFile(file_name);

    cout << "\n\t\t\tDelete Product Record";
    cout << "\n\nEnter the ID of the Product : ";
    cin >> productId;

    if (product_id_Trie.search(productId) == true) {
        cout << "\nEnter the name of the Product : ";
        cin >> productName;

        if (product_data_Trie.search(productId + productName) == true) {
            auto it = products.begin();
            while (it != products.end()) {
                if (it->getName() == productName && it->getID() == productId) {
                    cout << "\n\t\tProduct Record deleted\n";
                    cout << "Product name: " << it->getName() << "\nProduct ID: " << it->getID();
                    product_id_Trie.remove(productId);
                    product_data_Trie.remove(productId + productName);
                    it = products.erase(it);  
                    cin.get();
                    break;
                } else {
                    ++it;
                }
            }

            writeAllProductsToFile(products, file_name);
            cin.get();
        } else {
            cout << "Product with this Name and ID combination not found." << endl;
            cin.get();
        }
    } else {
        cout << "Product with this ID not found." << endl;
        cin.get();
    }
}



void refillProduct() {
    string file_name = getFileName();
    system("cls");
    string productId;
    string productName;
    vector<Product> products = readProductsFromFile(file_name);

    cout << "\nEnter Product ID: ";
    cin >> productId;

    if (product_id_Trie.search(productId) == true) {
        cout << "\nEnter Product name: ";
        cin >> productName;

        if (product_data_Trie.search(productId + productName) == true) {
            int quantityToAdd;
            cout << "\nEnter the number of quantity you want to refill: ";
            quantityToAdd = getNumericInput(1,100);

            for (auto &product : products) {
                if (product.getID() == productId && product.getName() == productName) {
                     product.refill(quantityToAdd);

                   
                        cout << "\n\t\tProduct Updated\n";
                        cout << "Name: " << product.getName() << " , ID: " << product.getID()
                             << " , Price: " << product.getPrice() << " , Quantity: " << product.getQuantity() << "\n";
                    break;  
                }
            }

            writeAllProductsToFile(products, file_name);
        } else {
            cout << "Product with this ID and Name combination not found...\n";
            cin.get();
        }
    } else {
        cout << "Product with this ID is not found...\n";
        cin.get();
    }

    cin.get();
}


void reduceProduct() {
    string file_name = getFileName();
    system("cls");
    string productId;
    string productName;
    vector<Product> products = readProductsFromFile(file_name);

    cout << "\n\nEnter Product ID: ";
    cin >> productId;

    if (product_id_Trie.search(productId) == true) {
        cout << "\nEnter Product name: ";
        cin >> productName;

        if (product_data_Trie.search(productId + productName) == true) {
            int quantityToReduce;
            cout << "\n\nEnter the number of quantity you want to Reduce: ";
            for (auto &product : products) {
                if (product.getID() == productId && product.getName() == productName) {
                    quantityToReduce = getNumericInput(0,product.getQuantity());
                     product.reduce(quantityToReduce);
                        cout << "\n\t\tProduct Updated\n";
                        cout << "Name: " << product.getName() << " , ID: " << product.getID()
                             << " , Price: " << product.getPrice() << " , Quantity: " << product.getQuantity() << "\n";
                    break;  
                } 
            }
            writeAllProductsToFile(products, file_name);
        } else {
            cout << "Product with this Name and ID combination not found." << endl;
            cin.get();
        }
    } else {
        cout << "Product with this ID not found." << endl;
        cin.get();
    }
    cin.get();
}


void applyDiscount() {
    system("cls");
    string file_name = getFileName();
    string productId;
    string productName;
    vector<Product> products = readProductsFromFile(file_name);

    cout << "\n\nEnter Product ID: ";
    cin >> productId;

    if (product_id_Trie.search(productId) == true) {
        cout << "\nEnter Product name: ";
        cin >> productName;

        if (product_data_Trie.search(productId + productName) == true) {
        for (auto &product : products) {
            if (product.getName() == productName && product.getID() == productId) {
                double discountPercentage;
                cout << "\nEnter the discount percentage: ";
                discountPercentage = getDoubleNumericInput(1.0,50.0);

               product.setDiscount(discountPercentage);
                    cout << "\n\t\tDiscount Applied\n\n";
                    cout << "Name: " << product.getName() << " , ID: " << product.getID()
                         << " , Price: " << product.getPrice() << " , Quantity: " << product.getQuantity()
                         << " , Discount: " << product.getDiscount() << "\n\n";

                cin.get();
                break;  
        }
        }
        writeAllProductsToFile(products, file_name);

        }
        else {
        cout << "Product with this ID and Name combination not found." << endl;
        cin.get();
        cin.get();
    }

    } 
    else {
        cout << "Product with this ID not found." << endl;
        cin.get();
        cin.get();
    }
}



void doGiveaway() {
    double rewardPercentage = 0.05;  
    double maxRewardAmount = 10000.0;  

    vector<User> users = readUsersFromFile();

    if (users.empty()) {
        cout << "No users found.\n";
        cin.get();
        return;
    }

 int i = 1;
    const int columnWidth = 15;

    cout << setw(4) << "No" << setw(columnWidth) << "ID" << setw(columnWidth) << "Name"
         << setw(20) << "           Total Purchase" << setw(columnWidth) << "    Reward amount" << "\n";

    cout << setw(4) << setfill('=') << "=" << setw(columnWidth) << "="
         << setw(columnWidth) << "=" << setw(columnWidth) << "=" << setw(columnWidth) << "====================" << setfill(' ') << "\n";

    for ( auto &user : users) {
        double rewardAmount = user.getTotalPurchases() * rewardPercentage;
        rewardAmount = min(rewardAmount, maxRewardAmount);

        user.depositsMoney(rewardAmount);

        cout << setw(4) << i << setw(columnWidth) << user.getID() << setw(columnWidth) << user.getName()
             << setw(20) << fixed << setprecision(2) << user.getTotalPurchases()
             << setw(columnWidth) << fixed << setprecision(2) << rewardAmount << "\n";
        i++;
    }
    writeAllUsersToFile(users);
cout << setw(4) << setfill('=') << "=" << setw(columnWidth) << "="
         << setw(columnWidth) << "=" << setw(columnWidth) << "=" << setw(columnWidth) << "====================" << setfill(' ') << "\n\n";

    cout << "Giveaway successful! Reward amounts deposited.\n";
    cin.get();
}

void removeUser() {
    system("cls");
    string temp;
    string id;
    string pass;
    vector<User> users = readUsersFromFile();
    cout << "\n\t\t\tDelete User";
    cout << "\n\nEnter User ID: ";
    cin >> id;
    if (user_id_Trie.search(id) == true) {
        cout << "\nEnter User name: ";
        cin >> temp;
        if (user_data_Trie.search(id + temp) == true) {
            auto it = users.begin();
            while (it != users.end()) {
                if (it->getName() == temp && it->getID() == id ) {
                    cout << "\n\t\tUser Record deleted\n";
                    cout << "User ID: " << it->getID() << "\nUser Name: " << it->getName();
                    user_id_Trie.remove(id);
                    user_data_Trie.remove(id + temp);
                    it = users.erase(it);  
                    cin.get();
                    break;
                } else {
                    ++it;
                }
            }
            writeAllUsersToFile(users);
            cin.get();
        }
        else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
        }
    }
     else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
    cin.get();
}

void resetUserPerformance() {
    vector<User> users = readUsersFromFile();

    if (users.empty()) {
        cout << "No users found.\n";
        cin.get();
        return;
    }

    int i = 1;
const int columnWidth = 15;

cout << setw(4) << "Serial No" << setw(columnWidth) << "ID" << setw(columnWidth) << "  Name"
     << setw(columnWidth) << "            Total Purchase" << "\n";

cout << setw(4) << setfill('=') << "=" << setw(columnWidth) << "="
     << setw(columnWidth) << "=" << setw(columnWidth) << "=============" << setfill(' ') << "\n";

for ( auto &user : users) {
    cout << setw(4) << i << setw(columnWidth) << user.getID() << setw(columnWidth) << user.getName()
         << setw(columnWidth) << user.getTotalPurchases() << "\n";

    user.resetTotalPurchase();
    i++;
}

    writeAllUsersToFile(users);
    cout << setw(4) << setfill('=') << "=" << setw(columnWidth) << "="
     << setw(columnWidth) << "=" << setw(columnWidth) << "=============" << setfill(' ') << "\n\n";
    cout << "User performance reset successful! Total purchases set to 0.0.\n";
    cin.get();
}

void changerProductName() {
    string file_name = getFileName();
    system("cls");
    string productId;
    string productName;
    vector<Product> products = readProductsFromFile(file_name);

    cout << "\nEnter Product ID: ";
    cin >> productId;

    if (product_id_Trie.search(productId) == true) {
        cout << "\nEnter Product name: ";
        cin >> productName;

        if (product_data_Trie.search(productId + productName) == true) {

            for (auto &product : products) {
                if (product.getID() == productId && product.getName() == productName) {
                    string newProductName;
                    cout << "\nEnter the new name for the product: ";
                    cin >> newProductName;
                    product.setName(newProductName);
                    cout << "\n\t\tProduct Name Updated\n";
                    cout << "ID: " << product.getID() << " , New Name: " << product.getName() << "\n";
                    product_data_Trie.remove(productId+productName);
                    product_data_Trie.insert(productId+newProductName);
                    cin.get();
                    break;
                }
            }

            writeAllProductsToFile(products, file_name);
        } else {
            cout << "Product with this ID and Name combination not found.\n";
            cin.get();
        }
    } else {
        cout << "Product with this ID not found.\n";
        cin.get();
    }
    cin.get();
}

void changeProductPrice() {
    string file_name = getFileName();
    system("cls");
    string productId;
    string productName;
    vector<Product> products = readProductsFromFile(file_name);

    cout << "\nEnter Product ID: ";
    cin >> productId;

    if (product_id_Trie.search(productId) == true) {
        cout << "\nEnter Product name: ";
        cin >> productName;

        if (product_data_Trie.search(productId + productName) == true) {

            for (auto &product : products) {
                if (product.getID() == productId && product.getName() == productName) {
                   double newPrice;
                    cout << "\nEnter the new price for the product: ";
                    newPrice = getDoubleNumericInput(0.00001, 1000000000.0);
                    product.setPrice(newPrice);
                    cout << "\n\t\tProduct Price Updated\n";
                    cout << "ID: " << product.getID() << " , New Price: " << product.getPrice() << "\n";
                    break;
                }
            }

            writeAllProductsToFile(products, file_name);
        } else {
            cout << "Product with this ID and Name combination not found.\n";
            cin.get();
        }
    } else {
        cout << "Product with this ID not found.\n";
        cin.get();
    }
    cin.get();
}


