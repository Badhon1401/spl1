#include<bits/stdc++.h>
#include "dealerFeatures.cpp"
#include "userFeatures.cpp"
using namespace std;
int main()
{	

	populate_Product_Trie_With_ProductData();
	populate_User_Trie_With_UserData();
	int i,j;
	string password="dealer";
	shop:
	cout<<"\n|============ WELCOME TO BADHON'S STORE ============|\n";
	cout<<"====================================================";
	cout<<"\n\t\t   1. Dealer Mode\n\n\t\t   2. Customer Mode\n\n\t\t   3.Exit";
	cout<<"\n====================================================";
	cout<<"\nEnter Your Choice:";
	cin>>j;
	if(j==1)
	{
	system("cls");
	string pass;
	cout<<"Enter Dealer Password...\n";
	cin>>pass;
	if(pass==password){
    system("cls");
	dealermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Sales Report\n6. Apply discount\n7. Remove User\n8. List of Users\n9. Reduce\n10. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
	system("cls");
	addNewProduct();
	goto dealermenu;
	}
	else if(i==2)
	{
	system("cls");
	displayProducts();cin.get();goto dealermenu;
	}
	else if(i==3)
	{   system("cls");
		refillProduct();cin.get();goto dealermenu;
	}
	else if(i==4)
	{	
		system("cls");
		removeProduct();cin.get();goto dealermenu;
	}
	else if(i==5)
	{
		salesReport();cin.get();goto dealermenu;
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
	displayUsers();goto dealermenu;
	}
	else if(i==9)
	{
	reduceProduct();goto dealermenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop...";
	cin.get();
	exit(0);
}
	}
	else{
		system("cls");
		cout<<"Wrong password!!! Access denied to the system...\n";
		cin.get();
		cin.get();
		goto shop;
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
	cout<<"\n\n1. Purchase\n2. Display stock\n3. Delete Account\n4. Change Account Name\n5. Change Account Password\n6. Exit:";
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
	displayProducts();cin.get();goto custmenu;
	}
	else if(h==3)
	{
	system("cls");
	deleteAccount();cin.get();goto custmenu;
	}
	else if(h==4)
	{
	system("cls");
	changeAccountName();cin.get();goto custmenu;
	}
	else if(h==5)
	{
	system("cls");
	changeAccountPassword();cin.get();goto custmenu;
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
	cout<<"\n\t\t\tThanks for visiting the shop\n\n";
	cin.get();
	exit(0);
	}
	}	
	if(j==3){
		system("cls");
		cout<<"\n\t\t\tThanks for visiting the site\n\n";
		cin.get();
		exit(0);
	}
	cin.get();
}