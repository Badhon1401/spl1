#include<bits/stdc++.h>
#include "customerFeatures.cpp"
using namespace std;

void addnew()
{
    system("cls");
	display();
	cin.get();
	system("cls");
    int num=0;
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>num;
    if (num>0)
    {
	ofstream fout("shop.dat",ios::binary|ios::app);
	for(int i=0;i<num;i++)
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
    cout << "Enter product name: ";
    cin >> productName;
    bool productFound = false;

    while (fin.read((char*)&st, sizeof(st))) {
        if (st.stock_check(productName) == 1) {
			 float discountPercentage;
			  cout << "Enter discount percentage: ";
    		  cin >> discountPercentage;
            st.setDiscount(discountPercentage);
            cout << "\nDiscount of " << discountPercentage << "% applied to " << productName << endl;
			cin.get();
            productFound = true;
        }
        fout.write((char*)&st, sizeof(st)); 
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
void refill()
{
	system("cls");
	string temp;int qty;
	int i=0;
	long pos=0;
	display();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	fstream fio("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stock_check(temp)==1)
	    { 
		  cout<<"\n\nEnter quantity: \n"<<endl;
	      cin>>qty;
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
	 display(); 
}

void remove()
{
	system("cls");	
	 int i=0;
     string temp;
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     ofstream fout("temp.dat",ios::binary);
     ifstream fin("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof()){
	    if(st.stock_check(temp)==1)
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

void sales(){
	cout<<"So here is the sales report:\n";
	cout<<"Name\t\t\t"<<"Item sold\n";
	cout<<"======\t\t\t"<<"=========\n";
	 ifstream fin("shop.dat",ios::binary);
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