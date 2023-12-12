#include<bits/stdc++.h>
#include "customerFeatures.cpp"
using namespace std;

void removeProduct(){
    string file_name=getFileName();
   system("cls");	
    int i=0;
     string temp;
     string id;
     vector<Product> products= readProductsFromFile(file_name);
     vector<Product> pro;
     cout<<"\n\t\t\tDelete Product Record";
     cout<<"\n\nEnter the name of the Product : ";
     cin>>temp;
     cout<<"\nEnter the ID of the Product : ";
     cin>>id;
     if(product_Trie.search(temp+id)==true){
     ifstream fin(file_name,ios::binary);
     for (const auto& product : products) {
        if (product.getName() == temp && product.getID()==id) {
            i++;
		  cout<<"\n\t\tProduct Record deleted\n";
          cout<<"Product name: "<<product.getName()<<"\nProduct ID: "<<product.getID();
          product_Trie.remove(temp+id);
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
     
	 cin.get();
     }
      else{
    cout << "Product with this Name and ID not found." << endl;
    cin.get();
    }
     
}

void refillProduct(){
    string file_name=getFileName();
  system("cls");
     int i=0;	
     string temp;
     string id;
     vector<Product> products= readProductsFromFile(file_name);
     vector<Product> pro;

     cout<<"\n\nEnter Product name: ";
     cin>>temp;
     cout<<"\nEnter Product ID: ";
     cin>>id;

     if(product_Trie.search(temp+id)==true){
     ifstream fin(file_name,ios::binary);
     for (auto& product : products) {
        if (product.getName() == temp && product.getID()==id) {
            i++;
            int num;
            cout<<"\n\nEnter the number of quantity you wanna refill: ";
            cin>>num;
            int b=0;
            b=product.refill(num);
            if(b==1){
		  cout<<"\n\t\tProduct Updated\n";
         cout<<"Name: "<<product.getName()<<" , ID: "<<product.getID()<<" , Price: "<<product.getPrice()<<" , Quantity: "<<product.getQuantity()<<"\n";
         cin.get();
            }
          pro.push_back(product);
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
        cin.get();
    }
   
        writeAllProductsToFile(pro,file_name);
     
}
     else{
        cout<<"Account with this name and id is not found...\n";
        cin.get();
     }
}

void reduceProduct(){
    string file_name=getFileName();
  system("cls");
     int i=0;	
     string temp;
     string id;
     vector<Product> products= readProductsFromFile(file_name);
     vector<Product> pro;

     cout<<"\n\nEnter Product name: ";
     cin>>temp;
     cout<<"\nEnter Product ID: ";
     cin>>id;

     if(product_Trie.search(temp+id)==true){
     ifstream fin(file_name,ios::binary);
     for (auto& product : products) {
        if (product.getName() == temp && product.getID()==id) {
            i++;
            int num;
            cout<<"\n\nEnter the number of quantity you wanna Reduce: ";
            cin>>num;
            int b=0;
            b=product.reduce(num);
            if(b==1){
		  cout<<"\n\t\tProduct Updated\n";
         cout<<"Name: "<<product.getName()<<" , ID: "<<product.getID()<<" , Price: "<<product.getPrice()<<" , Quantity: "<<product.getQuantity()<<"\n";

            }
          pro.push_back(product);
          cin.get();
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
        cout<<"Account with this name and id is not found...\n";
        cin.get();
     }
}

void addNewProduct() {
    string file_name=getFileName();
    int num=0;
    string name;
    string id;
     float price;
    int quantity;
    while (true) {
        system("cls");
        cout << "\nEnter the No. of Products that you wish to add: ";
        cin >> num;
        if (num > 0) {
            break;
        } else {
            cout << "Invalid input...Please enter a number greater than 0...\n";
            cin.get();
        }
    }
    for(int i=0;i<num;i++){
    system("cls");
    cout << "Enter Product Name: ";
    cin >> name;
    cout << "Enter Product ID: ";
    cin >> id;
            if(product_Trie.search(name+id)==1){
                cout<<"This product is already in the inventory\n";
                cin.get();
                cin.get();
               continue;
                
            }
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
            cin >> quantity;
            if (quantity < 1) {
                cout << "\nInvalid Quantity! It has to be 1 or more...\n";
                cin.get();
            } else {
                break;
            }
        }

    Product pr(name, id, price,quantity);
    writeNewProductToFile(pr,file_name);
    }
    
}

void applyDiscount() {
    string file_name=getFileName();
    system("cls");
    int i = 0;
    string temp;
    string id;
    vector<Product> products = readProductsFromFile(file_name);
    vector<Product> pro;

    cout << "\n\nEnter Product name: ";
    cin >> temp;
    cout << "\nEnter Product ID: ";
    cin >> id;

    if (product_Trie.search(temp + id) == true) {
        ifstream fin(file_name, ios::binary);
        for (auto& product : products) {
            if (product.getName() == temp && product.getID() == id) {
                i++;
                float disc;
                cout << "\nEnter the discount percentage: ";
                cin >> disc;

                // Apply discount using the setDiscount function
                int b=product.setDiscount(disc);
                if(b==1){
                cout << "\n\t\tDiscount Applied\n\n";
                cout << "Name: " << product.getName() << " , ID: " << product.getID()
                     << " , Price: " << product.getPrice() << " , Quantity: " << product.getQuantity()
                     << " , Discount: " << product.getDiscount() << "\n";
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

        cin.get();
    } else {
        cout << "Product with this Name and ID not found." << endl;
        cin.get();
    }
}

