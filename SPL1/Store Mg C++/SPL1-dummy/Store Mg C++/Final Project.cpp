#include<bits/stdc++.h>
#include "dealerFeatures.cpp"
#include "userFeatures.cpp"
using namespace std;
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
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Sales Report\n6. Apply discount\n7. Remove User\n8. List of Users\n9. Exit:";
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
	else if(i==7)
	{
		removeUser();goto dealermenu;
	}
	else if(i==8)
	{
	listOfUsers();goto dealermenu;
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
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Sign in\n2. Sign up\n3. Exit\n";
	cout<<"\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1){
	system("cls");
	bool b;
	b=signIn();cin.get();
	if(b==false){goto customermenu;	}
	else{
		int h;
		system("cls");
		custmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n1. Purchase\n2. Display stock\n3. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
		cout<<"\n\n Enter your Choice :\t";
		cin>>h;
		if (h==1)
	{
	system("cls");
	customerShopping();goto custmenu;
	}
	else if(h==2)
	{
	system("cls");
	display();cin.get();goto custmenu;
	}
    else 
	{
	system("cls");
	cout<<"\n\n\n\tThanks for visiting the shop";
	cin.get();
	exit(0);
	}

	}
	}
	if(i==2){
	system("cls");
	signUp();cin.get();goto customermenu;	
	}
	 else 
	{
	system("cls");
	cout<<"\n\n\n\tThanks for visiting the shop";
	cin.get();
	exit(0);
	}
	}	
	cin.get();
}