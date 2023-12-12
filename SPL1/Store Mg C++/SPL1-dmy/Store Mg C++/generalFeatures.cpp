#include<bits/stdc++.h>
#include "product.cpp"
#include "trie.cpp"
using namespace std;

string getGenre(string file_name) {
    if (file_name == "grocery.dat") {
        return "grocery";
    } else if (file_name == "food&beverage.dat") {
        return "food&beverage";
    } else if (file_name == "electronics.dat") {
        return "electronics";
    } else if (file_name == "book&stationary.dat") {
        return "book&stationary";
    } else if (file_name == "fashion&beauty.dat") {
        return "fashion&beauty";
    } else if (file_name == "healthcare.dat") {
        return "healthcare";
    } 
    else {
        // Handle unrecognized file names
		return "homeappliance";
    }
}
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
