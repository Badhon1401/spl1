#include<bits/stdc++.h>
#include "productFeatures.cpp"
using namespace std;
void customerShopping() {
    // Assuming you have a way to obtain user information (ID, name) within the function
    string name;
    string id;
    string pas;
    int i=0;
    cout << "\nEnter your ID: ";
    cin >> id;
    cout << "\nEnter your name: ";
    cin >> name;

    if (user_Trie.search(id)) {
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

        vector<pair<Product, int>> purchases;
        int continueShopping = 1;

        while (continueShopping == 1) {

            string file_name = getFileName(); // Assuming you have a function to get the file name
            string code=getGenre(file_name);
            string productId;
            string productName;
            int quantity;
            cin.get();
            cout << "\nEnter product ID: ";
            cin >> productId;
            cout << "\nEnter product name: ";
            cin >> productName;
            cout << "Enter quantity: ";
            cin >> quantity;

            // Assuming you have a ProductTrie for checking product existence
            if (product_Trie.search(code+productId)) {
                vector<Product> products = readProductsFromFile(file_name);

                // Find the product in the inventory
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
                cin >> continueShopping;
                writeAllProductsToFile(products, file_name);
                system("cls");
            } else {
                cout << "Product with this ID not found. Please check the ID and try again." << endl;
                cin.get();
                cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
                cin >> continueShopping;
                if(continueShopping==0 && i==0){
                system("cls");
                return;
                }
                else{
                    system("cls");
                }
            }
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
        currentUser.depositPurchaseAmount(totalAmount);
        // Update the user's information in the file
        vector<User> updatedUsers;
        for (const auto& user : users) {
            if (user.getID() == currentUser.getID()) {
                updatedUsers.push_back(currentUser);
            } else {
                updatedUsers.push_back(user);
            }
        }

        writeAllUsersToFile(updatedUsers);

        cin.get();
    } else {
        cout << "Account with this ID not found. Please sign up." << endl;
        cin.get();
    }
}
