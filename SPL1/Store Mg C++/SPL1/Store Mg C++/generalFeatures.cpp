#include<bits/stdc++.h>
#include "product.cpp"
#include "trie.cpp"
using namespace std;

double getPositiveNumericInput() {
    double numericInput;
    while (true) {
        if (cin >> numericInput && numericInput > 0) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number greater than 0: ";
            cin.get();
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
            cin.get();
            cout<<"Your input has to be in between "<<lowerLimit<<" to "<<upperLimit<<". Now enter new input :";
        }
    }
    return numericInput;
}
double getDoubleNumericInput(double lowerLimit, double upperLimit) {
    double doubleInput;
    while (true) {
        if (cin >> doubleInput) {
            if (doubleInput >= lowerLimit && doubleInput <= upperLimit) {
                if (cin.peek() == '\n') {
                    break;  
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter only double values within the specified range.\n";
                }
            } else {
                cout << "Input out of range. Please enter a value between " << lowerLimit << " and " << upperLimit << ".\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter only double values within the specified range.\n";
            cin.get();
        }
    }
    return doubleInput;
}

string getFileName(){
	int i;
	cout<<"Enter the category of products...\n1.Grocery\n2.Foods and Bevareges\n";
    cout<<"3.Elecetronics\n4.Books and stationary\n5.Fasion and Beuty\n6.HealthCare\n";
    cout<<"7.Home Appliance\n";
	i=getNumericInput(1,7);
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
		return "homeapplaince.dat";
	}
}
