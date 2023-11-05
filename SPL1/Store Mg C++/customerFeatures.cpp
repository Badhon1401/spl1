#include<bits/stdc++.h>
#include "generalFeatures.cpp"
using namespace std;
void customerShopping() {
    vector<pair<Stock, int>> purchases;
    int k=1;
	string productName;
	int quantity;
	int l=0;
    while(k==1){
        vector<Stock> products;
		int m=0;
    	system("cls");
        cout << "\nAvailable Products:" << endl;
        display();
		cin.get();
        system("cls");
        cout << "Enter product name: ";
        cin >> productName;
     cout << "Enter quantity: ";
        cin >> quantity;
    ifstream fin("shop.dat", ios::binary);

    if (!fin.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return;
    }
	int j=0;
    // Read data from the file into the products vector
    while (fin.read((char*)&st, sizeof(st))) {
		j++;
        products.push_back(st);
    }

    fin.close();

    if (products.empty()) {
        cout << "\n\n\t\t\t!!Empty record room!!";
        cin.get();
        return;
    }
        // Find the product in the inventory
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].stock_check(productName) == 1) {
				m=1;
                if (products[i].getQuantity() >= quantity) {
                        products[i].withdraw(quantity);
                        purchases.push_back(make_pair(products[i], quantity));
						l=1;
                    } 
                else {
                    cout << "Insufficient stock for this quantity." << endl;
					 cin.get();
                }
                break;
            }
        }

     ofstream fout("temp.dat",ios::binary);
     for(int i=0;i<j;i++){
		st=products[i];
		fout.write((char*)&st,sizeof(st));
	 }
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
	if(m==0){
            cout<<"The product is not available...\n";
			 cin.get();
	}
        cout<<"If you want to continue shoping enter 1 otherwise 0\n";
        cin>>k;
	}
	if(l==1){
    // Print the receipt
    cout << "\n\n=============================\n";
    cout << "       Payment Receipt\n";
    cout << "=============================\n";
    cout << "Product\t\tQuantity\tPrice\n";
    cout << "---------------------------------\n";
    float totalAmount = 0;
    for (const auto& purchase : purchases) {
        cout<<purchase.first.getName()<< "\t" << setw(8) << purchase.second << "\t" << setw(6) << fixed << setprecision(2) << purchase.first.getPrice() * purchase.second << endl;
        totalAmount += purchase.first.getPrice() * purchase.second;
    }
    cout << "---------------------------------\n";
    cout << "Total Amount with discount:\t" << fixed << setprecision(2) << totalAmount << endl;
    cout << "=============================\n";
    cout << "Thank you for shopping with us!\n";
    cin.get();
	}
	cin.get();
}