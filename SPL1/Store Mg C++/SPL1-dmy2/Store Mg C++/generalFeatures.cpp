#include<bits/stdc++.h>
#include "product.cpp"
#include "trie.cpp"
using namespace std;

int getNumericInput() {
    int numericInput;
    while (true) {
        if (cin >> numericInput) {
            if (cin.peek() == '\n') {
                break;  
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter only numeric values.\n";
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter only numeric values.\n";
        }
    }
    return numericInput;
}

double getPositiveNumericInput() {
    double numericInput;
    while (true) {
        if (cin >> numericInput && numericInput > 0) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number greater than 0: ";
        }
    }
    return numericInput;
}

int getNumericInput(int lowerLimit, int upperLimit) {
    int numericInput;
    while (true) {
        if (cin >> numericInput) {
            if (numericInput >= lowerLimit && numericInput <= upperLimit) {
                if (cin.peek() == '\n') {
                    break;  
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter only numeric values within the specified range.\n";
                }
            } else {
                cout << "Input out of range. Please enter a value between " << lowerLimit << " and " << upperLimit << ".\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter only numeric values within the specified range.\n";
        }
    }
    return numericInput;
}

string getFileName(){
	int i;
	cout<<"Enter the category of products...\n1.Grocery\n2.Foods and Bevareges\n3.Elecetronics\n4.Books and stationary\n5.Fasion and Beuty\n6.HealthCare\n7.Home Appliances\n";
	i=getNumericInput();
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
}
