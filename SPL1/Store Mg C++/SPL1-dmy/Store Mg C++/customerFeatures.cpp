#include<bits/stdc++.h>
#include "productFeatures.cpp"
using namespace std;

void customerShopping() {
    string name;
    string id;
    string pas;
    cout << "\nEnter your ID: ";
    cin >> id;
    cout << "\nEnter your name: ";
    cin >> name;

    if (user_id_Trie.search(id)) {
        cout << "\nEnter your Password: ";
        cin >> pas;
        vector<User> users = readUsersFromFile();
        User currentUser;

        for (auto& user : users) {
            if (user.getName() == name && user.getID() == id && user.getPassword() == pas) {
                currentUser = user;
                cout << "Welcome, " << currentUser.getName() << "!" << endl;
                cin.get();
                system("cls");
                break;
            }
        }

        if (currentUser.getName().empty()) {
            cout << "Account not found. Please sign up." << endl;
            cin.get();
            return;
        }

        string file_name = getFileName();
        string code = getGenre(file_name);
        vector<pair<Product, int>> purchases;
        int continueShopping = 1;
        string dm_file_name="dm"+file_name;
        vector<Product> products = readProductsFromFile(file_name);
        writeAllProductsToFile(products,dm_file_name);
        while (continueShopping == 1) {
            int i=0;
            cout<<"Do you wanna see the inventory or not? Is enter 1 otherwise 0\n";
            i=getNumericInput();
            cin.get();
            if(i==1){

                displayProducts(dm_file_name);
            }
            system("cls");
            string productId;
            string productName;
            int quantity;

            cin.get();
            cout << "\nEnter product ID: ";
            cin >> productId;
            cout << "\nEnter product name: ";
            cin >> productName;
            cout << "Enter quantity: ";
            quantity = getPositiveNumericInput();

            if (product_id_Trie.search(code + productId)) {
                for (size_t i = 0; i < products.size(); ++i) {
                    if (products[i].getID() == productId && products[i].getName() == productName) {
                        if (products[i].getQuantity() >= quantity) {
                            products[i].withdraw(quantity);
                            purchases.push_back(make_pair(products[i], quantity));
                            products[i].setNoOfBuyers();
                            cout << "Product added to your cart.\n";
                            i++;
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
               
            } else {
                cout << "Product with this ID not found. Please check the ID and try again." << endl;
                cin.get();
                cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
                continueShopping = getNumericInput();
                if (continueShopping == 0 && i == 0) {
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
        float totalAmount = 0;
        for (const auto& purchase : purchases) {
            cout << purchase.first.getName() << "\t" << setw(8) << purchase.second << "\t"
                 << setw(6) << fixed << setprecision(2) << purchase.first.getPrice() * purchase.second << endl;
            totalAmount += purchase.first.getPrice() * purchase.second;
        }
        cout << "---------------------------------\n";
        cout << "Total Amount with discount:\t" << fixed << setprecision(2) << totalAmount << endl;
        cout << "=============================\n\n";
        int x;
        cout<<"Enter one of the option...\n1. Go for final payment\n2. Cancel Order\n";;
        x=getNumericInput(1,2);
        if(x==1){
        if(currentUser.getBalance()>=totalAmount){
        currentUser.depositPurchaseAmount(totalAmount);
         currentUser.withDrawMoney(totalAmount);
        vector<User> updatedUsers;
        for (const auto& user : users) {
            if (user.getID() == currentUser.getID()) {
                updatedUsers.push_back(currentUser);
            } else {
                updatedUsers.push_back(user);
            }
        }
         remove(dm_file_name.c_str());
        writeAllProductsToFile(products,file_name);
        writeAllUsersToFile(updatedUsers);
        cout << "Thank you for shopping with us!\n";
        cin.get();
        }
        else{
            system("cls");
            cout<<"You dont have enough balance to pay the bill. So sorry we have to cancel the order...\n";
            cin.get();
            cin.get();
        }
        }
        if(x==2){
            system("cls");
            cout<<"Your order has been canceled. Thanks for visiting our shop...\n";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Account with this ID not found. Please sign up." << endl;
        cin.get();
    }
}
