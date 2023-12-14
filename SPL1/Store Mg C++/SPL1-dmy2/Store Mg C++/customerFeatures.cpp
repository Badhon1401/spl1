#include<bits/stdc++.h>
#include "productFeatures.cpp"
using namespace std;

void customerShopping(User& currentUser) {

    vector<User> users = readUsersFromFile();
        int x=0;
        string file_name = getFileName();
        vector<pair<Product, int>> purchases;
        int continueShopping = 1;
        string dm_file_name="dm"+file_name;
        vector<Product> products = readProductsFromFile(file_name);
        writeAllProductsToFile(products,dm_file_name);
        while (continueShopping == 1) {
            int m=0;
            cout<<"Do you wanna see the inventory or not? Is enter 1 otherwise 0\n";
            m=getNumericInput();
            cin.get();
            if(m==1){
                displayProducts(dm_file_name);
            }
            system("cls");
            string productId;
            string productName;
            int quantity;

            cout << "\nEnter product ID: ";
            cin >> productId;

            if (product_id_Trie.search(productId)) {
                  cout << "\nEnter product name: ";
                    cin >> productName;
                    if(product_data_Trie.search(productId+productName)){
                         cout << "Enter quantity: ";
                        quantity = getPositiveNumericInput();
                for (size_t i = 0; i < products.size(); ++i) {
                    if (products[i].getID() == productId && products[i].getName() == productName) {
                        if (products[i].getQuantity() >= quantity) {
                            products[i].withdraw(quantity);
                            purchases.push_back(make_pair(products[i], quantity));
                            products[i].setNoOfBuyers();
                            cout << "Product added to your cart.\n";
                            x++;
                        } else {
                            cout << "Insufficient stock for this quantity.\n";
                        }
                        break;
                    }
                }

                    cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
                    continueShopping = getNumericInput();
                    writeAllProductsToFile(products, dm_file_name);
                    system("cls");
                    }
                    else {
                cout << "Product with this ID and Name not found. Please check the ID and try again." << endl;
                cin.get();
                cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
                continueShopping = getNumericInput();
                if (continueShopping == 0 && x == 0) {
                    system("cls");
                    return;
                } else {
                    system("cls");
                }
            }

               
            } else {
                cout << "Product with this ID not found. Please check the ID and try again." << endl;
                cin.get();
                cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
                continueShopping = getNumericInput();
                if (continueShopping == 0 && x == 0) {
                    system("cls");
                    return;
                } else {
                    system("cls");
                }
            }
        }

        cout << "\n\n=============================\n";
        cout << "       Payment Receipt\n";
        cout << "=============================\n";
        cout << "Product\t\tQuantity\tPrice\n";
        cout << "---------------------------------\n";
        double totalAmount = 0;
        for (const auto& purchase : purchases) {
            cout << purchase.first.getName() << "\t" << setw(8) << purchase.second << "\t"
                 << setw(6) << fixed << setprecision(2) << purchase.first.getPrice() * purchase.second << endl;
            totalAmount += purchase.first.getPrice() * purchase.second;
        }
        cout << "---------------------------------\n";
        cout << "Total Amount with discount:\t" << fixed << setprecision(2) << totalAmount << endl;
        cout << "=============================\n\n";
        int t;
        cout<<"Enter one of the option...\n1. Go for final payment\n2. Cancel Order\n";;
        t=getNumericInput(1,2);
        if(t==1){
        if(currentUser.getBalance()>=totalAmount){
        
        for (auto& user : users) {
            if (user.getID() == currentUser.getID()) {
                user.depositPurchaseAmount(totalAmount);
                user.withDrawMoney(totalAmount);
                currentUser=user;
                break;
            } 
        }
        remove(dm_file_name.c_str());
        writeAllProductsToFile(products,file_name);
        writeAllUsersToFile(users);
        cout << "Thank you for shopping with us!\n";
        cin.get();
        }
        else{
            system("cls");
            cout<<"You dont have enough balance to pay the bill. So sorry we have to cancel the order...\n";
             remove(dm_file_name.c_str());
            cin.get();
            cin.get();
        }
        }
        if(t==2){
            system("cls");
            cout<<"Your order has been canceled. Thanks for visiting our shop...\n";
            remove(dm_file_name.c_str());
            cin.get();
            cin.get();
        }
 } 