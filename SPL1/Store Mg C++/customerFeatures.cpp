#include<bits/stdc++.h>
#include "productFeatures.cpp"
using namespace std;

bool signIn(User& us) {
    string id;
    string name;
    string pas;
     cout << "\nEnter your ID: ";
        cin >> id;
    if(user_id_Trie.search(id)==true){
        cout << "\nEnter your Name: ";
        cin >> name;
        if(user_data_Trie.search(id+name)==true){
            cout << "\nEnter your Password: ";
            cin >> pas;
            vector<User> users = readUsersFromFile();
            for (const auto& user : users) {
                if (user.getName() == name && user.getID()==id && user.getPassword()==pas) {
                    us=user;
                    cout << "Welcome, " << user.getName() << "!" << endl;
                        cin.get();
                        cin.get();
                        return true;
        }
    }

    cout << "Password did not match..." << endl;
    cin.get();
    cin.get();
    return false;
    }
    else{
        cout << "Account with this ID and Name not found. Please sign up." << endl;
        cin.get();
        cin.get();
        return false;
    }
    }
    else{
    cout << "Account with this ID not found. Please sign up." << endl;
    cin.get();
    cin.get();
    return false;
    }
}

void signUp() {
    string name;
    string id;
    string pass;
     while(true){
    cout << "Enter your ID: ";
    cin >> id;
            if(user_id_Trie.search(id)==1){
                cout<<"This id is already in used please use a separate one...\n";          
            }
            else{
               break; 
            }
    }
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your Password: ";
    cin >> pass;
    User newUser(id,name,pass);
     user_id_Trie.insert(id);
     user_data_Trie.insert(id+name);
    writeNewUserToFile(newUser);
    
}

void changeAccountName(User& currentUser){
    system("cls");
    string old_name;
    string id;
    string password;
    vector<User> users= readUsersFromFile();

     cout<<"\n\nEnter your ID: ";
     cin>>id;
     if(id==currentUser.getID()){
     cout<<"\nEnter your old name: ";
     cin>>old_name;
     if(old_name==currentUser.getName()){
     cout<<"\nEnter your password: ";
     cin>>password;
    if(password==currentUser.getPassword()){
     ifstream fin("user.dat",ios::binary);
     for (auto& user : users) {
        if (user.getID()==id && user.getName() == old_name && user.getPassword()==password) {
            string new_name;
            cout<<"\n\nEnter your new name: ";
            cin>>new_name;
            if(user.changeName(old_name,id,password,new_name)){
		  cout<<"\n\t\tAccount Updated\n";
          cout<<"Account ID: "<<user.getID()<<"\nAccount Name: "<<user.getName()<<"\nAccount Password: "<<user.getPassword();
          currentUser.setName(new_name);
          user_data_Trie.remove(id+old_name);
          user_data_Trie.insert(id+new_name);
          break;
            }
	    }
    }
    fin.close();
     writeAllUsersToFile(users);  
	 cin.get();
    }

       else{
                 cout << "Your entered Password is wrong. You have to enter correct user information to delete the account...\n";
                cin.get();
                cin.get();
            }
        } else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
}

void depositMoney(User& us) {

    double depositAmount;
    cout << "Enter the amount you want to deposit: ";
   depositAmount=getPositiveNumericInput();
    vector<User> users = readUsersFromFile();
    for (auto& u : users) {
        if (u.getID() == us.getID()) {
            u.depositsMoney(depositAmount);
            us=u;
            break;
        }
    }
    writeAllUsersToFile(users);

    cout << "Deposit successful! Your new balance is: " << us.getBalance() << endl;
    cin.get(); 
    
}

void deleteAccount(User& currentUser) {
    system("cls");
    string temp;
    string id;
    string pass;
    vector<User> users = readUsersFromFile();
    cout << "\n\t\t\tDelete Account";
    cout << "\n\nEnter your ID: ";
    cin >> id;
    if (id==currentUser.getID()) {
        cout << "\nEnter your name: ";
        cin >> temp;
        if (temp==currentUser.getName()) {
            cout << "\nEnter your Password: ";
            cin >> pass;
            if(pass==currentUser.getPassword()){
            auto it = users.begin();
            while (it != users.end()) {
                if (it->getName() == temp && it->getID() == id && it->getPassword() == pass) {
                    cout << "\n\t\tAccount deleted\n";
                    cout << "Account ID: " << it->getID() << "\nAccount Name: " << it->getName() << "\nAccount Password: " << it->getPassword();
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
            else{
                 cout << "Your entered Password is wrong. You have to enter correct user information to delete the account...\n";
                cin.get();
                cin.get();
            }
        } else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
}

void changeAccountPassword(User& currentUser){
    system("cls");
    string name;
    string id;
    string password;
    vector<User> users= readUsersFromFile();

     cout<<"\n\nEnter your ID: ";
     cin>>id;
     if(id==currentUser.getID()){
     cout<<"\nEnter your name: ";
     cin>>name;
     if(name==currentUser.getName()){
     cout<<"\nEnter your old password: ";
     cin>>password;
   if(password==currentUser.getPassword()){
     ifstream fin("user.dat",ios::binary);
     for (auto& user : users) {
        if (user.getID()==id && user.getName() == name && user.getPassword()==password) {
            string new_password;
            cout<<"\n\nEnter your new password: ";
            cin>>new_password;
            if(user.changePassword(name,id,password,new_password)){
		  cout<<"\n\t\tAccount Updated\n";
          cout<<"Account ID: "<<user.getID()<<"\nAccount Name: "<<user.getName()<<"\nAccount Password: "<<user.getPassword();
          break;
            }
	    }
    }
    fin.close();
     writeAllUsersToFile(users);  
      }
      
       else{
                 cout << "Your entered Password is wrong. You have to enter correct user information to delete the account...\n";
                cin.get();
                cin.get();
            }
        } else {
            cout << "Your entered User Name is wrong. You have to enter correct user information to delete the account...\n";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Your entered ID is wrong. You have to enter correct user information to delete the account.....\n";
        cin.get();
    }
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
    if(product_id_Trie.search(id)){
    cout << "Enter the product name: ";
    cin>>name;
    if(product_data_Trie.search(id+name)){
    for (auto& product : products) {
        if (product.getID() == id && product.getName() == name) {
            cout << "\nExisting Details:\n";
            cout << "ID: " << product.getID() << "\nName: " << product.getName()
                 << "\nRating: " << product.getRating() << "\n";
                 cin.get();
                 float rate;
                cout << "Enter Rating: ";
                rate=getNumericInput(0,10);
                product.setRating(rate); 
                cout << "\nUpdated Details:\n";
                cout << "ID: " << product.getID() << "\nName: " << product.getName()
                 << "\nRating: " << product.getRating() << "\n";          
                break;
            }
    }

            writeAllProductsToFile(products, file_name);
        }
          else{
        cout<<"Product with this ID and Name not found...\n";
        cin.get();
        cin.get();
    }
    }
    
    else{
        cout<<"Product with this ID not found...\n";
        cin.get();
        cin.get();
    }

}


void customerShopping(User& currentUser) {

    vector<User> users = readUsersFromFile();
        int x=0;
        string file_name = getFileName();
        vector<pair<Product, int>> purchases;
        int continueShopping = 1;
        string dm_file_name="dm"+file_name;
        vector<Product> products = readProductsFromFile(file_name);
        while (continueShopping == 1) {
            writeAllProductsToFile(products,dm_file_name);
            int m=0;
            cout<<"Do you wanna see the inventory or not? Is enter 1 otherwise 0\n";
            m=getNumericInput(0,1);
    
            if(m==1){
                system("cls");
                displayProducts(dm_file_name);
                cin.get();
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
                         cout << "\nEnter quantity: ";
                        quantity = getNumericInput(1,100);
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
                    continueShopping = getNumericInput(0,1);
                    writeAllProductsToFile(products, dm_file_name);
                    system("cls");
                    }
                    else {
                cout << "Product with this ID and Name not found. Please check the ID and try again." << endl;
                cin.get();
                cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
                continueShopping = getNumericInput(0,1);
                if (continueShopping == 0 && x == 0) {
                    system("cls");
                    remove(dm_file_name.c_str());
                    return;
                } else {
                    system("cls");
                }
            }

               
            } else {
                cout << "Product with this ID not found. Please check the ID and try again." << endl;
                cin.get();
                cout << "Do you want to continue shopping? (1 for Yes, 0 for No): ";
                continueShopping = getNumericInput(0,1);
                if (continueShopping == 0 && x == 0) {
                    system("cls");
                    remove(dm_file_name.c_str());
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
            totalAmount += purchase.first.getPrice() *(1-(purchase.first.getDiscount()/100)) * purchase.second;
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

 void searchProduct() {
    string productId, name;

    cout << "Enter product ID: ";
    cin >> productId;
    cout << "Enter product Name: ";
    cin >> name;

    if (product_id_Trie.search(productId) == true) {
        if (product_data_Trie.search(productId + name) == true) { 
                cout << "Product Found!\n";
                cout << "ID: " << productId<< "\n";
                cout << "Name: " << name << "\n";
        
            }
        else {
        cout << "User with this ID and Name combination does not exist.\n";
        cin.get();
        cin.get();
    }

    } else {
        cout << "User with this ID does not exist.\n";
        cin.get();
        cin.get();
    }
}
