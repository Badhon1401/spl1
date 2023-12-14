#include<bits/stdc++.h>
#include "dealerFeatures.cpp"
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
	j=getNumericInput(1,3);
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
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Sales Report\n6. Apply discount\n7. Remove User\n8. List of Users\n9. Reduce\n10. User Performance\n11. Giveaway\n12. Reset User Performance\n13. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	i=getNumericInput(1,13);
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
		refillProduct();goto dealermenu;
	}
	else if(i==4)
	{	
		system("cls");
		removeProduct();cin.get();goto dealermenu;
	}
	else if(i==5)
	{	
		system("cls");
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
		displayUsers();cin.get();goto dealermenu;
	}
	else if(i==9)
	{	
		system("cls");
		reduceProduct();goto dealermenu;
	}
	else if(i==10)
	{	
		system("cls");
		printUsersByTotalPurchases();cin.get();goto dealermenu;
	}
	if(i==11){
		system("cls");
		doGiveaway();cin.get();goto dealermenu;
	}
	if(i==12){
		system("cls");
		resetUserPerformance();cin.get();goto dealermenu;
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
	i=getNumericInput(1,3);
	cin.get();
	if(i==1){
	system("cls");
	User currentUser;
	if(!signIn(currentUser)){goto customermenu;	}
	else{
		int h;
		system("cls");
		custmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n1. Purchase\n2. Display stock\n3. Delete Account\n4. Change Account Name\n5. Change Account Password\n6. Recommendation\n7. Do rating\n8. Deposit Money\n9. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
		cout<<"\n\n Enter your Choice :\t";
		h=getNumericInput(1,9);
		if (h==1)
	{
	system("cls");
	customerShopping(currentUser);goto custmenu;
	}
	else if(h==2)
	{
	system("cls");
	displayProducts();cin.get();goto custmenu;
	}
	else if(h==3)
	{
	system("cls");
	deleteAccount(currentUser);cin.get();goto custmenu;
	}
	else if(h==4)
	{
	system("cls");
	changeAccountName(currentUser);cin.get();goto custmenu;
	}
	else if(h==5)
	{
	system("cls");
	changeAccountPassword(currentUser);cin.get();goto custmenu;
	}
	else if(h==6)
	{	
		system("cls");
		int n;
		cout<<"Choose one of the option...\n1. Recommendation Based On Rating\n2. Recommendation Based On No of Buyers\n3. Recommendation Based On No of Copies Sold\n4. Overall Rating\n";
		n=getNumericInput(1,4);
		system("cls");
		if(n==1){
			string file_name=getFileName();
			vector<Product> products=readProductsFromFile(file_name);
			productsByRating(products);	
		}
		if(n==2){
			string file_name=getFileName();
			vector<Product> products=readProductsFromFile(file_name);
			productsByBuyers(products);	
		}
		if(n==3){
			string file_name=getFileName();
			vector<Product> products=readProductsFromFile(file_name);
			productsBySoldCopies(products);	
		}
		if(n==4){
			string file_name=getFileName();
			vector<Product> products=readProductsFromFile(file_name);
			productsByOverallPerformance(products);	
		}
		cin.get();goto custmenu;
	}
	else if(h==7)
	{
	system("cls");
	doRating();cin.get();goto custmenu;
	}
	if(h==8){
	system("cls");
	depositMoney(currentUser);cin.get();goto custmenu;
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