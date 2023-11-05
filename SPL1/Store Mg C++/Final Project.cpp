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
		quantity-=qty;
		sold+=qty;
		cout<<"\n\nStock updated.\n";
	 cin.get();
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
	cin.get();
	system("cls");
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
    if (n>0)
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
	cout<<"\n\nNo items to be added";
	cin.get();
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
	cin.get();
    system("cls");
    ifstream fin("shop.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary); // Temporary file to store modified records

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return;
    }

    string productName;
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
			cin.get();
			cin.get();
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
		cin.get();
		cin.get();
    }
    system("cls");
    display();
}
void sales(){
	cout<<"So here is the sales report:\n";
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
		 cin.get();
		  fin.close();
	 	 return;
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
     if(i!=1){
       cout<<"\n\n!!Record not found!!";
	   cin.get();
	 }
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
void remove()
{
	system("cls");	
	 int i=0;
     string temp;
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
	 cin.get();
}
void customerShopping() {
    vector<pair<string, int>> purchases;
    vector<stock> products;
    int k=1;
	string productName;
	int quantity;
	int l=0;
    while(k==1){
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
            if (products[i].stock_check(productName) == 0) {
				m=1;
                if (products[i].getQuantity() >= quantity) {
                        products[i].withdraw(quantity);
                        purchases.push_back(make_pair(productName, quantity));
						l=1;
                    } 
                else {
                    cout << "Insufficient stock for this quantity." << endl;
					 cin.get();
                }
                break;
            }
        }

     fout.open("temp.dat",ios::binary);
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
        cout<< purchase.first << "\t" << setw(8) << purchase.second << "\t" << setw(6) << fixed << setprecision(2) << products[0].getPrice() * purchase.second << endl;
        totalAmount += products[0].getPrice() * purchase.second;
    }
    cout << "---------------------------------\n";
    cout << "Total Amount with discount:\t" << fixed << setprecision(2) << totalAmount << endl;
    cout << "=============================\n";
    cout << "Thank you for shopping with us!\n";
    cin.get();
	}
	cin.get();
}
int main()
{
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
	display();cin.get();goto dealermenu;
	}
	else if(i==3)
	{   system("cls");
		sales();cin.get();
		refill();cin.get();goto dealermenu;
	}
	else if(i==4)
	{
		remove();cin.get();goto dealermenu;
	}
	else if(i==5)
	{
		sales();cin.get();goto dealermenu;
	}
	else if(i==6)
	{
		applyDiscount();goto dealermenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop...";
	cin.get();
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
	system("cls");
	customerShopping();goto customermenu;
	}
	else if(i==2)
	{
	system("cls");
	display();cin.get();goto customermenu;
	}
    else 
	{
	system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop";
	cin.get();
	exit(0);
}
	}	
	cin.get();
}
