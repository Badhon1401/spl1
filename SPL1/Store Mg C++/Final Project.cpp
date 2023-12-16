#include<bits/stdc++.h>
#include "dealerFeatures.cpp"
using namespace std;

int main()
{	

	populate_Product_Trie_With_ProductData();
	populate_User_Trie_With_UserData();
	int i,j;
	string password="dealer";
	HomeMenu:
	system("cls");
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
	DealerMenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Manage Products\n2. Manage Users\n3. See Product Realted Stats\n4. See User Related Stats\n5. Back to Home Menu\n6. Exit\n";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	i=getNumericInput(1,6);
	if(i==1)
	{	
		
		int w;
		ManageProduct:
		system("cls");
		cout<<"1. Add new Products\n2. Refill Product\n3. Reduce Product\n4. Remove Product\n5. Display Products\n6. Change Product Related Data\n7. Search Product\n8. Back to Dealer Menu\n9. Exit\n";
		cout<<"\n\n Enter your Choice :\t";
		w=getNumericInput(1,9);
		if(w==1){
			system("cls");
			addNewProduct();
			goto ManageProduct;

		}
		if(w==2){
			system("cls");
			refillProduct();
			goto ManageProduct;
		}
		if(w==3){
			system("cls");
			reduceProduct();
			goto ManageProduct;
		}
		if(w==4){
			system("cls");
			removeProduct();
			goto ManageProduct;
		}
		if(w==5){
			system("cls");
			displayProducts();
			goto ManageProduct;
		}
		if(w==6){
			int u;
			system("cls");
			cout<<"1. Change Product Name\n2. Change Product Price\n3. Apply Discount\n4. Back \n5. Exit\n";
			cout<<"\n\n Enter your Choice :\t";
			u=getNumericInput(1,5);
			if(u==1){
				system("cls");
				changerProductName();
				goto ManageProduct;
			}
			if(u==2){
				system("cls");
				changeProductPrice();
				goto ManageProduct;
			}
			if(u==3){
				system("cls");
				applyDiscount();
				goto ManageProduct;
			}
			if(u==4){
				system("cls");
				goto ManageProduct;
			}
			else{
				system("cls");
				cout<<"\n\n\tSee you soon!!!\n\n";
				cin.get();
				exit(0);
			}
		}
		if(w==7){
			system("cls");
			searchProduct();
			goto ManageProduct;

		}
		if(w==8){
			system("cls");
			goto DealerMenu;
		}
		else{
			system("cls");
				cout<<"\n\n\tSee you soon!!!\n\n";
				cin.get();
				exit(0);

		}
		
	}
     if(i==2)
	{
		int u;
		ManageUser:
	system("cls");
	cout<<"1. Remove User\n2. Do Giveaway\n3. Reset User Performance\n4. Search User\n5. Back to Dealer Menu\n6. Exit\n";
	cout<<"\n\n Enter your Choice :\t";
			u=getNumericInput(1,6); 
			if(u==1){
				system("cls");
					removeUser();goto ManageUser;

			}
			if(u==2){
				system("cls");
					doGiveaway();cin.get();goto ManageUser;

			}
			if(u==3){
				system("cls");
					resetUserPerformance();cin.get();goto ManageUser;

			}
			if(u==4){
				system("cls");
					searchUser();cin.get();goto ManageUser;

			}
			if(u==5){
			system("cls");
			goto DealerMenu;
		}
		else{
			system("cls");
				cout<<"\n\n\tSee you soon!!!\n\n";
				cin.get();
				exit(0);

		}

	}
	 if(i==3)
	{  
		ProductStats:
		 system("cls");
	
		cout << "=============================================\n";
    cout << "               PRODUCT STATISTICS            \n";
    cout << "=============================================\n";
    cout << "1. Display All Products\n";
    cout << "2. Sales Report\n";
    cout << "3. Details of All Products\n";
    cout << "4. Products by Rating\n";
    cout << "5. Products by Number of Buyers\n";
    cout << "6. Products by Number of Sold Copies\n";
    cout << "7. Products by Overall Performance\n";
    cout << "8. Revenue Report\n";
    cout << "9. Low Stock Products\n";
    cout << "10. Highly Rated Products\n";
    cout << "11. Products with Discounts\n";
    cout << "12. Top Discounted Products\n";
    cout << "13. Total Revenue\n";
	cout << "14. Back to Dealer Menu\n";
    cout << "0. Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice (0-14): ";
	int choice;

   
       choice=getNumericInput(0,14);
           system("cls");
        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                salesReport();
                break;
            case 3:
                detailsOfAllProducts();
                break;
            case 4:
                productsByRating(readProductsFromFile(getFileName()));
                break;
            case 5:
                productsByBuyers(readProductsFromFile(getFileName()));
                break;
            case 6:
                productsBySoldCopies(readProductsFromFile(getFileName()));
                break;
            case 7:
                productsByOverallPerformance(readProductsFromFile(getFileName()));
                break;
            case 8:
                revenueReport();
                break;
            case 9:
                lowStockProducts();
                break;
            case 10:
                highRatedProducts();
                break;
            case 11:
                productsWithDiscounts();
                break;
            case 12:
                topDiscountedProducts(readProductsFromFile(getFileName()));
                break;
            case 13:
                totalRevenue();
                break;
			case 14:
                goto DealerMenu;
                break;
            case 0:
                cout << "See you soon. Goodbye!\n";
				cin.get();
				exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
		cin.get();
		goto ProductStats;

   
	}
	if(i==4)
	{	
		UserStats:
		system("cls");
		cout << "=============================================\n";
    cout << "               USER STATISTICS               \n";
    cout << "=============================================\n";
    cout << "1. Display All Users\n";
    cout << "2. Details of All Users\n";
    cout << "3. Users by Total Purchases\n";
    cout << "4. Search User\n";
    cout << "5. User with Maximum Total Purchases\n";
    cout << "6. Average Total Purchases\n";
	 cout << "7. Back to Dealer Menu\n";
    cout << "0. Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice (0-7): ";
	int choice;
   
       choice=getNumericInput(0,7);
	   system("cls");
	    switch (choice) {
            case 1:
                displayUsers();
                break;
            case 2:
                detailsOfAllUsers();
                break;
            case 3:
                printUsersByTotalPurchases();
                break;
            case 4:
                searchUser();
                break;
            case 5:
                findUserWithMaxTotalPurchases();
                break;
            case 6:
                calculateAverageTotalPurchases();
                break;
			case 7:
                goto DealerMenu;
                break;
            case 0:
                cout << "See you soon. Goodbye!\n";
				cin.get();
				exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
		cin.get();
		goto UserStats;

	}
	 if(i==5)
	{	
		system("cls");
		goto HomeMenu;
	}
	else{
            cout << "See you soon. Goodbye!\n";
				cin.get();
				exit(0);
	}

	}
	else{
		system("cls");
		cout<<"Wrong password!!! Access denied to the system...\n";
		cin.get();
		cin.get();
		goto HomeMenu;
	}
	}
	
	
	if(j==2)
	{
	customermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Sign in\n2. Sign up\n3. Back to Home Menu\n4. Exit\n";
	cout<<"\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	i=getNumericInput(1,4);
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
	cout<<"\n\n1. Purchase\n2. Display stock\n3. Delete Account\n4. Change Account Name\n5. Change Account Password\n6. Recommendation\n7. Do rating\n8. Deposit Money\n9. Search Product\n10. Back to Home menu\n11. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
		cout<<"\n\n Enter your Choice :\t";
		h=getNumericInput(1,11);
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
	else if (h == 6) {
    system("cls");
    int n;
    cout << "Choose one of the options...\n";
    cout << "1. Recommendation Based On Rating\n";
    cout << "2. Recommendation Based On No of Buyers\n";
    cout << "3. Recommendation Based On No of Copies Sold\n";
    cout << "4. Overall Rating\n";
    cout << "5. Top Discounted Products\n";
	 cout << "6. Discounted Products\n";

    n = getNumericInput(1, 6); 
    system("cls");
    string file_name = getFileName();
    vector<Product> products = readProductsFromFile(file_name);

    if (n == 1) {
        productsByRating(products);
    } else if (n == 2) {
        productsByBuyers(products);
    } else if (n == 3) {
        productsBySoldCopies(products);
    } else if (n == 4) {
        productsByOverallPerformance(products);
    } else if (n == 5) {
        int numTopProducts;
        cout << "Enter the number of top discounted products to display: ";
        numTopProducts = getNumericInput(1, INT_MAX);
        topDiscountedProducts(products, numTopProducts);
    }

	else{
		productsWithDiscounts();

	}

    cin.get();
    goto custmenu;
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
	if(h==9){
		system("cls");
		searchProduct();
		goto custmenu;
	}
	if(h==10){
	system("cls");
	goto HomeMenu;
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
	if(i==3){
	system("cls");
	goto HomeMenu;
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