#include<bits/stdc++.h>
#include "customerFeatures.cpp"
using namespace std;

void addnew()
{
    system("cls");
	cin.get();
	system("cls");
    int num=0;
	string name;
    float price;
    int quantity;
    string id;
	string file_name=getFileName();
	while(1){
			system("cls");
			cout<<"\nEnter the No. of Products that you wish to add: ";
    		cin>>num;
		if(num>0){
			break;
		}
		else{
			cout<<"Invalid input...Please enter a number greater than 0...\n";
			cin.get();
		}
   
	}

	ofstream fout(file_name,ios::binary|ios::app);
	for(int i=0;i<num;i++)
	{	
		system("cls");
		cout << "Enter name: \n";
    	cin >> name;
    
    while (true) {
        ifstream fin(file_name, ios::binary);
        int flag = 1;
        cout << "Enter ID: \n";
        cin >> id;

        while (!fin.eof()) {
            fin.read((char*)&st, sizeof(st));
            if (!fin.eof()) {
                if (st.getID() == id) {
                    cout << "This ID is already in use. Please use a different one...\n";
                    cin.get();
                    cin.get();
                    flag = 0;
                    fin.close();
                    break;
                }
            }
        }

        fin.close();
        if (flag == 1) {
            break;
        }
    }

    while (true) {
        cout << "Enter Price: \n";
        cin >> price;
        if (price <= 0.0) {
            cout << "Invalid Price! It has to be greater than 0...\n";
            cin.get();
        } else {
            break;
        }
    }

    while (true) {
        cout << "Enter quantity: \n";
        cin >> quantity;
        if (quantity < 1) {
            cout << "Invalid Quantity! It has to be 1 or more...\n";
            cin.get();
        } else {
            break;
        }
    }
	    st.get(name,id,price,quantity);
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nitem updated\n";
		cin.get();
    }
    cout<<"\n\nStock Updated!!!";
    fout.close();
    cin.get();
    system("cls");
}

void applyDiscount() {
	cin.get();
    system("cls");
	string file_name=getFileName();
    ifstream fin(file_name, ios::binary);
    ofstream fout("temp.dat", ios::binary);

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return;
    }

    string productName;
    string idd;
    cout << "Enter product name: \n";
    cin >> productName;
    cout << "Enter product ID: \n";
    cin >> idd;
    bool productFound = false;

    while (fin.read((char*)&st, sizeof(st))) {
        if (st.stock_check(productName,idd) == 1) {
			 float discountPercentage;
			   while(1){
     				  cout << "Enter discount percentage: \n";
        			cin >> discountPercentage;
       				 if(discountPercentage>0.0 && discountPercentage<100.0){
						break;
					 }
					 else{
            		cout<<"Invalid Discount Percentage! It has to be in between 0 and 100 ...\n";
            		cin.get();
					 }
        		}
            st.setDiscount(discountPercentage);
            cout << "\nDiscount of " << discountPercentage << "% applied to " << productName << endl;
			cin.get();
			cin.get();
            productFound = true;
        }
        fout.write((char*)&st, sizeof(st)); 
    }

    fin.close();
    fout.close();

const char* old_file_name = file_name.c_str();
const char* new_file_name = "temp.dat";
remove(old_file_name);
rename(new_file_name, old_file_name);

    if (!productFound) {
        cout << "\nProduct not found!" << endl;
		cin.get();
		cin.get();
    }
    system("cls");
}
void refill()
{
	system("cls");
	string temp;int qty;
    string idd;
	int i=0;
	long pos=0;
	string file_name=getFileName();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
    cout<<"Enter the products ID \n"<<endl;
	cin>>idd;
	fstream fio(file_name,ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stock_check(temp,idd)==1)
	    { 
		  while(1){
     cout << "Enter quantity: \n";
        cin >> qty;
        if(qty<1){
            cout<<"Invalid Quantity! It has to be 1 or more...\n";
            cin.get();
        }
        else{
            break;
        }
    }
		  st.refill(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1){
       cout<<"\n\n!!Record not found!!";
	   fio.close(); 
	   cin.get();
	   return;
	 }
	fio.close();     
	 cin.get();
    system("cls");
}
void reduce()
{
	system("cls");
	string temp;int qty;
    string idd;
	int i=0;
	long pos=0;
	string file_name=getFileName();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
    cout<<"Enter the products ID \n"<<endl;
	cin>>idd;
	fstream fio(file_name,ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stock_check(temp,idd)==1)
	    { 
		  while(1){
     cout << "Enter quantity: \n";
        cin >> qty;
        if(qty<1){
            cout<<"Invalid Quantity! It has to be 1 or more...\n";
            cin.get();
        }
        else{
            break;
        }
    }
		  st.reduce(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1){
       cout<<"\n\n!!Record not found!!";
	   fio.close(); 
	   cin.get();
	   return;
	 }
	fio.close();     
	 cin.get();
    system("cls");
}

void remove()
{
	system("cls");	
	 int i=0;
	 string file_name=getFileName();
     string idd;
	 system("cls");
     string temp;
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     cout<<"Enter the products ID \n"<<endl;
	cin>>idd;
     ofstream fout("temp.dat",ios::binary);
     ifstream fin(file_name,ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof()){
	    if(st.stock_check(temp,idd)==1)
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
const char* old_file_name = file_name.c_str();
const char* new_file_name = "temp.dat";
remove(old_file_name);
rename(new_file_name, old_file_name);
	 cin.get();
}

void sales(){
	string file_name=getFileName();
	cout<<"So here is the sales report:\n";
	cout<<"Name\t\t\t"<<"Item sold\n";
	cout<<"======\t\t\t"<<"=========\n";
	 ifstream fin(file_name,ios::binary);
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