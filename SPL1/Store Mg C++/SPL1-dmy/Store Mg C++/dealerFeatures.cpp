#include<bits/stdc++.h>
#include "customerFeatures.cpp"
using namespace std;

void removeProduct(){
    string file_name=getFileName();
    string code=getGenre(file_name);
   system("cls");	
    int i=0;
     string temp;
     string id;
     vector<Product> products= readProductsFromFile(file_name);
     vector<Product> pro;
     cout<<"\n\t\t\tDelete Product Record";
     cout<<"\n\nEnter the ID of the Product : ";
     cin>>id;
     cout<<"\nEnter the name of the Product : ";
     cin>>temp;
     if(product_id_Trie.search(code+id)==true){
     ifstream fin(file_name,ios::binary);
     for (const auto& product : products) {
        if (product.getName() == temp && product.getID()==id) {
            i++;
		  cout<<"\n\t\tProduct Record deleted\n";
          cout<<"Product name: "<<product.getName()<<"\nProduct ID: "<<product.getID();
          product_id_Trie.remove(code+id);
          cin.get();
	    }
	    else{
          pro.push_back(product);
        }
    }
    fin.close();
    const char* old_file_name = file_name.c_str();
    remove(old_file_name);
	 cin.get();
    if(i==0){
        cout<<"Product not found...\n";
        cin.get();
    }
     
        writeAllProductsToFile(pro,file_name);
     
     }
      else{
    cout << "Product with this Name and ID not found." << endl;
    cin.get();
    }
     
}

void refillProduct(){
    string file_name=getFileName();
    string code=getGenre(file_name);
    system("cls");
    int i=0;
    string temp;
    string id;
    vector<Product> products= readProductsFromFile(file_name);
    vector<Product> pro;

     cout<<"\n\nEnter Product ID: ";
     cin>>id;
     cout<<"\nEnter Product name: ";
     cin>>temp;
     if(product_id_Trie.search(code+id)==true){
     ifstream fin(file_name,ios::binary);
     int k=0;
     for (auto& product : products) {
        if(k==0){
        if (product.getName() == temp && product.getID()==id) {
            int num;
            cout<<"\n\nEnter the number of quantity you wanna refill: ";
            num=getNumericInput();
            int b=0;
            b=product.refill(num);
            if(b==1){
                i++;
		  cout<<"\n\t\tProduct Updated\n";
         cout<<"Name: "<<product.getName()<<" , ID: "<<product.getID()<<" , Price: "<<product.getPrice()<<" , Quantity: "<<product.getQuantity()<<"\n";
         cin.get();
            }
            if(b==0){
                return;
            }
          pro.push_back(product);
          k=1;
	    }
	    else{
          pro.push_back(product);
        }
        }
        else{
             pro.push_back(product);
        }
    }
    fin.close();
    if(i==0){
        cout<<"Product not found...\n";
        cin.get();
        return;
    }
   
   const char* old_file_name = file_name.c_str();
    remove(old_file_name);
        writeAllProductsToFile(pro,file_name);
     
}
     else{
        cout<<"Product with this id is not found...\n";
     }
}

void reduceProduct(){
    string file_name=getFileName();
    string code=getGenre(file_name);
    system("cls");
     int i=0;	
     string temp;
     string id;
     vector<Product> products= readProductsFromFile(file_name);
     vector<Product> pro;

     cout<<"\n\nEnter Product ID: ";
     cin>>id;
      cout<<"\nEnter Product name: ";
     cin>>temp;

     if(product_id_Trie.search(code+id)==true){
        int k=0;
     ifstream fin(file_name,ios::binary);
     for (auto& product : products) {
        if(k==0){
        if (product.getName() == temp && product.getID()==id) {
            i++;
            int num;
            cout<<"\n\nEnter the number of quantity you wanna Reduce: ";
            num=getNumericInput();
            int b=0;
            b=product.reduce(num);
            if(b==1){
		  cout<<"\n\t\tProduct Updated\n";
         cout<<"Name: "<<product.getName()<<" , ID: "<<product.getID()<<" , Price: "<<product.getPrice()<<" , Quantity: "<<product.getQuantity()<<"\n";

            }
             if(b==0){
                return;
            }
          pro.push_back(product);
          k=1;
          cin.get();
	    }
	    else{
          pro.push_back(product);
        }
        }
        else{
            pro.push_back(product);
        }
    }
    fin.close();
   const char* old_file_name = file_name.c_str();
    remove(old_file_name);
    if(i==0){
        cout<<"Product not found...\n";
    }
   
        writeAllProductsToFile(pro,file_name);
     
	 cin.get();
}
     else{
        cout<<"Product with this name and id is not found...\n";
        cin.get();
        cin.get();
     }
}

void addNewProduct() {
    string file_name=getFileName();
    string code=getGenre(file_name);
    int num=0;
    string name;
    string id;
     float price;
    int quantity;
    while (true) {
        system("cls");
        cout << "\nEnter the No. of Products that you wish to add: ";
        num=getNumericInput();
        if (num > 0 && num<101) {
            break;
        } else {
            cout << "Invalid input...You can add atmost 100 items and atleast 1 item...\n";
            cin.get();
        }
    }
    for(int i=0;i<num;i++){
    system("cls");
    while(true){
    cout << "Enter Product ID: ";
    cin >> id;
            if(product_id_Trie.search(code+id)==1){
                cout<<"This product id is already in use please use a separate one...\n";
                cin.get();
            }
            else{
                break;
            }
    }
     cout << "Enter Product Name: ";
    cin >> name;
             while (true) {
            cout << "Enter Price: ";
            cin >> price;
            if (price <= 0.0) {
                cout << "\nInvalid Price! It has to be greater than 0...\n";
                cin.get();
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter quantity: ";
            quantity=getNumericInput();
            if (quantity < 1) {
                cout << "\nInvalid Quantity! It has to be 1 or more...\n";
                cin.get();
            } else {
                break;
            }
        }

    Product pr(id,name,price,quantity);
    writeNewProductToFile(pr,file_name);
    }
    
}

void applyDiscount() {
    system("cls");
    string file_name=getFileName();
    string code=getGenre(file_name);
    int i = 0;
    string temp;
    string id;
    vector<Product> products = readProductsFromFile(file_name);
    vector<Product> pro;

    cout << "\n\nEnter Product ID: ";
    cin >> id;
     cout << "\nEnter Product name: ";
    cin >> temp;
    if (product_id_Trie.search(code + id) == true) {
        ifstream fin(file_name, ios::binary);
        for (auto& product : products) {
            if (product.getName() == temp && product.getID() == id) {
                i++;
                float disc;
                cout << "\nEnter the discount percentage: ";
               disc=getNumericInput();

                int b=product.setDiscount(disc);
                if(b==1){
                cout << "\n\t\tDiscount Applied\n\n";
                cout << "Name: " << product.getName() << " , ID: " << product.getID()
                     << " , Price: " << product.getPrice() << " , Quantity: " << product.getQuantity()
                     << " , Discount: " << product.getDiscount() << "\n\n";
                }
                pro.push_back(product);
                cin.get();
            } else {
                pro.push_back(product);
            }
        }
        fin.close();
        const char* old_file_name = file_name.c_str();
        remove(old_file_name);
        if (i == 0) {
            cout << "Product not found...\n";
        }

        writeAllProductsToFile(pro, file_name);

    } else {
        cout << "Product with this Name and ID not found." << endl;
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
    for (auto& user : users) {
        double rewardAmount = user.getTotalPurchases() * rewardPercentage;
        rewardAmount = min(rewardAmount, maxRewardAmount);  

        user.depositsMoney(rewardAmount);

        cout << setw(4) << i << setw(10) << user.getID() << setw(10) << user.getName()
             << setw(15) << user.getTotalPurchases() << setw(15) << rewardAmount << "\n";
        i++;
    }

    writeAllUsersToFile(users);

    cout << "Giveaway successful! Reward amounts deposited.\n";
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
    for (auto& user : users) {
        cout << setw(4) << i << setw(10) << user.getID() << setw(10) << user.getName()
             << setw(15) << user.getTotalPurchases() << "\n";

        user.depositPurchaseAmount(-user.getTotalPurchases());  // Reset total purchases to 0.0
        i++;
    }

    writeAllUsersToFile(users);

    cout << "User performance reset successful! Total purchases set to 0.0.\n";
    cin.get();
}
