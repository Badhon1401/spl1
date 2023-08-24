#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
	char name[20],pass[10];
	float pr;
    int quant;
public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);    
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty)
{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();	
}
void stock::refil(int qty)
{	
		quant+=qty;
		cout<<"\n\nStock updated.";
	    getch();
}
int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()
{   
	cout<<"Enter name of the product followed by price and quantity...\n";
	cin>>name>>pr>>quant;
}
void stock::get2()
{
	cin>>name>>quant;
}

void stock::show()
{
	
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}
void addnew()
{
 //   cout<<"\n\n\nCongrats!!Access Granted!!\n\n";

    system("cls");
	//cout<<"\nEnter the Name followed By the price and then by the quantity\n"; 	
	disp();
	getch();
	system("cls");
	
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
	
    
    if (n!=0)
    {
	
	//int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	
	{
	    /*if(i==0)	
		{
		system("cls");
	}*/
		cout<<"\n\nInput the name, price and the quantity of item respectively\n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nitem updated";
		cin.get();
	}
    cout<<"\n\nStock Updated!!";
    

    fout.close();
    cin.get();
    system("cls");
    disp();
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";

}
}

int main()
{
	char pass[10];
	//pass2[10];
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO BADHON'S STORE ============|\n";
	/*
	getch();
	system("cls");
	cout<<"\n\t\t   STORE MANAGEMENT SYSTEM\n";	
	*/
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t ";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
	getch();
	
}
