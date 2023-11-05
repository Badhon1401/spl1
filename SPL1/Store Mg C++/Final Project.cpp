#include<bits/stdc++.h>
#include<fstream>
#include "trie.cpp"
using namespace std;
int i,n;
char c;
ifstream fin;
ofstream fout;
fstream fio;
void display();
class stock
{
	string name;
	float price;
    int quantity;
	int sold;
	float discount;
public:
	void get();
	void show();   
    void withdraw(int qty);
    void refil(int qty);
	int stock_check(string nm); 
	void sales_show(); 
	void setDiscount(float disc) {
        discount = disc;
    }
    float getDiscount() {
        return discount;
    }
	float getPrice() const {
        return price * (1 - discount / 100); // Apply discount to the price
    }
	int getQuantity(){
		return quantity;
	}
	string getName(){
		return name;
	}
}st;
//int stock::sold=0;
void stock::withdraw(int qty)
{
	if(quantity>=qty)
	{
		quantity-=qty;
		sold+=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price :"<<price*qty;
    }
	else {
	   cout<<"\n\nInsufficient stock";
	  	
	}
	 cin.get(c);
}
void stock::refil(int qty)
{	
		quantity+=qty;
		cout<<"\n\nStock updated.";
	    cin.get(c);
}
int stock::stock_check(string nm)
{
    if (name==nm)
        return 0; // Name matches
    else
        return -1; // Name does not match
}

void stock::get()
{   
	cout<<"Enter name of the product followed by price and quantity...\n";
	cin>>name>>price>>quantity;
	sold=0;
	discount=0;
}
void stock::show()
{
	cout<<"\n"<<name<<"\t\t\t"<<quantity<<"    "<<price<<"    "<<discount;

}
void stock::sales_show(){
	if(sold>0){
		cout<<"\n"<<name<<"\t\t\t"<<sold;
	}
	
}
void addnew()
{
    system("cls");
	display();
	cin.get(c);
	system("cls");
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
    if (n!=0)
    {
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	{
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nitem updated\n";
		cin.get();
    }
    cout<<"\n\nStock Updated!!!";
    fout.close();
    cin.get();
    system("cls");
    display();
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";

}
}
void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	double money;
	cout<<"Enter your net current balance..\n";
	cin>>money;
	system("cls");
	display();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);

     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stock_check(temp)==0)
	    {
		  st.withdraw(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }

     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    cin.get();
    system("cls");
	 display(); 
	cin.get(c);
}
void applyDiscount() {
    system("cls");
    ifstream fin("shop.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary); // Temporary file to store modified records

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return;
    }

    char productName[30];
    float discountPercentage;
    cout << "Enter product name: ";
    cin >> productName;
    cout << "Enter discount percentage: ";
    cin >> discountPercentage;

    bool productFound = false;

    while (fin.read((char*)&st, sizeof(st))) {
        if (st.stock_check(productName) == 0) {
            st.setDiscount(discountPercentage);
            cout << "\nDiscount of " << discountPercentage << "% applied to " << productName << endl;
            productFound = true;
        }
        fout.write((char*)&st, sizeof(st)); // Write records to the temporary file
    }

    fin.close();
    fout.close();

    // Replace the original file with the updated one
    remove("shop.dat");
    rename("temp.dat", "shop.dat");

    if (!productFound) {
        cout << "\nProduct not found!" << endl;
    }
	cin.get();
    system("cls");
    display();
}
void sales(){
	cout<<"Name\t\t\t"<<"Item sold\n";
	cout<<"======\t\t\t"<<"=========\n";
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {  
		 if(fin.tellg()<0)
	     {	
		 cout<<"\n\n\t\t\t!!Empty record room!!";
		 cin.get(c);
	 	 break;
		}
	     st.sales_show();
	  }
     }
     fin.close();
	 cin.get();
}
void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	display();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stock_check(temp)==0)
	    {
		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
	 cin.get();
    system("cls");
	 display(); 
}
void display()
{
	cout<<"\n==================================================================";
	cout<<"\n\n==============\tBadhon's Store\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPRODUCTS_NAME\tSTOCK AVAILABLE\t  PRICE\t  Discount";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	
		 cout<<"\n\n\t\t\t!!Empty record room!!";
		cin.get();
	 	 break;
		}
	    st.show();
	  }
     }
     fin.close();
	 cin.get();
}
void remove()
{
	system("cls");	
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof()){
	    if(st.stock_check(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
	 }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
	 cin.get(c);
}
void customerShopping() {
    vector<pair<string, int>> purchases;
    vector<stock> products;

    ifstream fin("shop.dat", ios::binary);

    if (!fin.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return;
    }

    // Read data from the file into the products vector
    while (fin.read((char*)&st, sizeof(st))) {
        products.push_back(st);
    }

    fin.close();

    if (products.empty()) {
        cout << "\n\n\t\t\t!!Empty record room!!";
        cin.get();
        return;
    }

    char productName[30];
    int quantity;

        system("cls");
        cout << "\nAvailable Products:" << endl;
        display();
        cin.get(c);
        system("cls");

        cout << "Enter product name: ";
        cin >> productName;

        cout << "Enter quantity: ";
        cin >> quantity;

        bool productFound = false;

        // Find the product in the inventory
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].stock_check(productName) == 0) {
                if (products[i].getQuantity() >= quantity) {
                        products[i].withdraw(quantity);
                        purchases.push_back(make_pair(productName, quantity));
                        productFound = true;
                    } 
                else {
                    cout << "Insufficient stock for this quantity." << endl;
                }
                break;
            }
        }

        if (!productFound) {
            cout << "Product not found or insufficient stock." << endl;
		}

    // Write the updated product data back to the file
    ofstream fout("shop.dat", ios::binary);
    for (const auto& product : products) {
        fout.write((char*)&product, sizeof(product));
    }
    fout.close();

    // Print the receipt
    cout << "\n\n=============================\n";
    cout << "       Payment Receipt\n";
    cout << "=============================\n";
    cout << "Product\t\tQuantity\tPrice\n";
    cout << "---------------------------------\n";
    float totalAmount = 0;
    for (const auto& purchase : purchases) {
        cout<< purchase.first << "\t" << setw(8) << purchase.second << "\t" << setw(6) << fixed << setprecision(2) << products[0].getPrice() * purchase.second << endl;
        totalAmount += products[0].getPrice() * purchase.second;
    }
    cout << "---------------------------------\n";
    cout << "Total Amount with discount:\t\t\t" << fixed << setprecision(2) << totalAmount << endl;
    cout << "=============================\n";
    cout << "Thank you for shopping with us!\n";
    cin.get();
}
int main()
{	
	fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	
		 cout<<"\n\n\t\t\t!!Empty record room!!";
		cin.get();
	 	 break;
		}
	    tr.insert(st.getName());
	  }
     }
     fin.close();
	int i,j;
	cout<<"\n|============ WELCOME TO BADHON'S STORE ============|\n";
	cout<<"====================================================";
	cout<<"\n\t\t   1. Dealer Mode\n\n\t\t   2. Customer Mode";
	cout<<"\n====================================================";
	cout<<"\nEnter Your Choice:";
	cin>>j;
	if(j==1)
	{
    system("cls");
	dealermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Sales Report\n6. Apply discount\n7. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
	addnew();
	cin.get(c);
	goto dealermenu;
	}
	else if(i==2)
	{
	system("cls");
	display();cin.get(c);goto dealermenu;
	}
	else if(i==3)
	{   system("cls");
		sales();
		refill();goto dealermenu;
	}
	else if(i==4)
	{
		remove();cin.get(c);goto dealermenu;
	}
	else if(i==5)
	{
		sales();cin.get(c);goto dealermenu;
	}
	else if(i==6)
	{
		applyDiscount();cin.get(c);goto dealermenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop...";
	cin.get(c);
	exit(0);
}
}	
	if(j==2)
	{
	customermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if (i==1)
	{
	customerShopping();cin.get(c);goto customermenu;
	}
	else if(i==2)
	{
	system("cls");
	display();cin.get(c);goto customermenu;
	}
    else 
	{
	system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop";
	cin.get(c);
	exit(0);
}
	}	
	cin.get(c);
}
