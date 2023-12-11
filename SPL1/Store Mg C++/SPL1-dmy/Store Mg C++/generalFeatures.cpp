#include<bits/stdc++.h>
#include "stock.cpp"
#include "trie.cpp"
using namespace std;
string getFileName(){
	int i;
	cout<<"Enter the category of products...\n1.Grocery\n2.Foods and Bevareges\n3.Elecetronics\n4.Books and stationary\n5.Fasion and Beuty\n6.HealthCare\n7.Home Appliances\n";
	cin>>i;
	system("cls");
	if(i==1){
		return "grocery.dat";
	}
	else if(i==2){
		return "food&bevarage.dat";
	}
	else if(i==3){
		return "electronics.dat";
	}
	else if(i==4){
		return "book&stationary.dat";
	}
	else if(i==5){
		return "fashion&beauty.dat";
	}
	else if(i==6){
		return "healthcare.dat";
	}
	else{
		return "homeapplainec.dat";
	}
	cin.get();
}

void loadProducts(Trie& tr,const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    while (file.good()) {     
        Stock newStock;
        file.read(reinterpret_cast<char*>(&newStock), sizeof(Stock));

        if (!file.fail() && !file.eof()) {
            tr.insert(newStock.getID());
        }
    }

    file.close();
}
void display()
{	
	string file_name=getFileName();	
	cout<<"\n==================================================================";
	cout<<"\n\n==============\tBadhon's Store\t==================";
	cout<<"\n\n==================================================================\n";
	cout << left << setw(20) <<"Name"
             << setw(10) << "ID"
             << setw(10) << "Quantity"
             << setw(10) << "Price"
             << setw(10) << "Discount";
	cout<<"\n============================================================\n";	
	ifstream fin(file_name,ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	
		 cout<<"\n\n\t\t\t!!Empty record room!!";
		fin.close();
	 	cin.get();
	 	 return;
		}
	    st.show();
	  }
     }
     fin.close();
	 cin.get();
}