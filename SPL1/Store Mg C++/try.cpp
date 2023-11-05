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
    }
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
	cout<<"Enter name -> price -> quantity -> discount...\n";
	cin>>name>>price>>quantity>>discount;
	sold=0;
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
	system("cls");
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
    if (n!=0)
    {
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	{
	    st.get();
        tr.insert(st.getName());
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
	string temp;int qty;
	long pos=0;
	system("cls");
	display();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	if(tr.search(temp)){
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
		  break;
	    }
     }
	 fio.close();
	}
     else{
       cout<<"\n\n!!Record not found!!";
	 }
     
    cin.get();
    system("cls");
	 display(); 
}
void applyDiscount() {
    system("cls");
     string productName;
    cout << "Enter product name: ";
    cin >> productName;
    if(tr.search(productName)){
    float discountPercentage;
    cout << "Enter discount percentage: ";
    cin >> discountPercentage;
    ifstream fin("shop.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary); // Temporary file to store modified records

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return;
    }

    while (fin.read((char*)&st, sizeof(st))) {
        if (st.stock_check(productName) == 0) {
            st.setDiscount(discountPercentage);
            cout << "\nDiscount of " << discountPercentage << "% applied to " << productName << endl;
        }
        fout.write((char*)&st, sizeof(st)); // Write records to the temporary file
    }

    fin.close();
    fout.close();

    // Replace the original file with the updated one
    remove("shop.dat");
    rename("temp.dat", "shop.dat");
    }
    else{
         cout<<"Product not found...\n";
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
	string temp;int qty;
	long pos=0;
	display();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
    if(tr.search(temp)){
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
		  break;
	    }
     }
     fio.close();
    }
    else{
        cout<<"Record not found...\n";
    }
	cin.get(c);
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
	 cin>>c;
}
void remove()
{
	system("cls");	
     string temp;
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     if(tr.search(temp)){
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
		  tr.remove(temp);
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
	 }
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
     }
     else{
        cout<<"\n\n!!Record not found!!";
     }
	 cin>>c;
}
void customerShopping() {
    vector<pair<string, int>> purchases;
    vector<stock> products;
    int k=1;
    while(k==1){
    system("cls");
        cout << "\nAvailable Products:" << endl;
        display();
        system("cls");
        string productName;
        cout << "Enter product name: ";
        cin >> productName;
        if(tr.search(productName)){
     int quantity;
     cout << "Enter quantity: ";
        cin >> quantity;
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
        // Find the product in the inventory
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].stock_check(productName) == 0) {
                if (products[i].getQuantity() >= quantity) {
                        products[i].withdraw(quantity);
                        purchases.push_back(make_pair(productName, quantity));
                    } 
                else {
                    cout << "Insufficient stock for this quantity." << endl;
                }
                break;
            }
        }

    // Write the updated product data back to the file
    ofstream fout("shop.dat", ios::binary);
    for (const auto& product : products) {
        fout.write((char*)&product, sizeof(product));
    }
    fout.close();
        }
        else{
            cout<<"The product is not available...\n";
        }
        cout<<"If you want to continue shoping enter 1 otherwise 0\n";
        cin>>k;
    }
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
    cout << "Total Amount with discount:\t" << fixed << setprecision(2) << totalAmount << endl;
    cout << "=============================\n";
    cout << "Thank you for shopping with us!\n";
    cin>>c;
}
void loadTrie(){
    ifstream fn;
    fn.open("shop.dat", ios::binary);
while (fn.read((char*)&st, sizeof(st))) {
    tr.insert(st.getName());
}
fn.close();
}
int main()
{	
	// vector<stock> products;
	// ifstream fn("shop.dat", ios::binary);
    // if (!fn.is_open()) {
    //     cout << "Error: Unable to open the file." << endl;
    //     return 0;
    // }

    // // Read data from the file into the products vector
    // while (fn.read((char*)&st, sizeof(st))) {
    //     products.push_back(st);
    // }

    // fn.close();
	//  for (size_t i = 0; i < products.size(); ++i) {
	// 	tr.insert(products[i].getName());
	//  }

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
	goto dealermenu;
	}
	else if(i==2)
	{
	system("cls");
	display();cin>>c;goto dealermenu;
	}
	else if(i==3)
	{   system("cls");
		sales();
		refill();cin>>c;goto dealermenu;
	}
	else if(i==4)
	{
		remove();cin>>c;goto dealermenu;
	}
	else if(i==5)
	{
		sales();cin>>c;goto dealermenu;
	}
	else if(i==6)
	{
		applyDiscount();cin>>c;goto dealermenu;
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
	customerShopping();cin>>c;goto customermenu;
	}
	else if(i==2)
	{
	system("cls");
	display();cin>>c;goto customermenu;
	}
    else 
	{
	system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop";
	cin.get(c);
	exit(0);
}
	}	
}