#include<bits/stdc++.h>
#include "stock.cpp"
using namespace std;

void display()
{
	cout<<"\n==================================================================";
	cout<<"\n\n==============\tBadhon's Store\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPRODUCTS_NAME\tSTOCK AVAILABLE\t  PRICE\t  Discount";
	cout<<"\n\n============================================================\n";	
	ifstream fin("shop.dat",ios::binary);
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