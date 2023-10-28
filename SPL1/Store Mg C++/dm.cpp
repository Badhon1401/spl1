#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
ifstream fn;
ofstream ft;
fstream fo;
struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
}nd;
class Trie {
//private:
	//Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}
Node* root;
	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i<static_cast<int>(word.size()); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i <static_cast<int>(word.size()); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}
	//  void trieUpdate(string word);
	//  bool trieSearch(string word);

}tr;
void trieUpdate(string word){
	ifstream inputFile("trie.dat",ios::binary);
	inputFile.read(reinterpret_cast<char*>(&tr),sizeof(tr));
	tr.insert(word);
	inputFile.close();
	// fout.open("temp.dat",ios::binary);
	// ft.open("tmp.dat",ios::binary);
    // fn.open("trie.dat",ios::binary);
	// fn.read((char*)&tr,sizeof(tr));
	// tr.insert(word);
	ofstream outputFile("trie.dat",ios::binary);
	outputFile.write(reinterpret_cast<const char*>(&tr),sizeof(tr));
	outputFile.close();
	// ft.write((char*)&tr,sizeof(tr));
    //  fn.close();
    //  ft.close();
    //  remove("trie.dat");
    //  rename("tmp.dat","trie.dat");
}
bool trieSearch(string word){
	ifstream inputFile("trie.dat",ios::binary);
	inputFile.read(reinterpret_cast<char*>(&tr),sizeof(tr));
	bool b=tr.search(word);
	 inputFile.close();
	// fn.open("trie.dat",ios::binary);
	// fn.read((char*)&tr,sizeof(tr));
	// bool b=tr.search(word);;
	// fn.close();
	// fo.open("trie.dat",ios::binary);
	// fo.read((char*)&tr,sizeof(tr));
	// fo.close();
	return b;
}
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void display();
static Trie trie;
class stock
{
	char name[20];
	float price;
    int quantity;
	int sold;
	//Trie trie;
public:
   // char name[20];
	void get();
	void show();   
    void withdraw(int qty);
    void refil(int qty);
	int stock_check(char nm[30]); 
	void sales_show(); 
}st;
//int stock::sold=0;
void stock::withdraw(int qty)
{
	if(quantity>=qty)
	{
		quantity-=qty;
		sold+=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<price*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();	
}
void stock::refil(int qty)
{	
		quantity+=qty;
		cout<<"\n\nStock updated.";
	    getch();
}
int stock::stock_check(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()
{   
	cout<<"Enter name of the product followed by price and quantity...\n";
	cin>>name>>price>>quantity;
	sold=0;
    trieUpdate(name);
}
void stock::show()
{
	cout<<"\n"<<name<<"\t\t\t"<<quantity<<"\t\t\t"<<price;

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
	getch();
	system("cls");
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
    if (n!=0)
    {
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	{
	    st.get();
		//trieUpdate(st.name);
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
	char temp[100];int qty;
	int i=0;
	long pos=0;
	display();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	if(trieSearch(temp)){

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
     fio.close();
    }
    else{
       cout<<"\n\n!!Record not found!!";
       getch();
    }
    cin.get();
    system("cls");
	 display(); 
	getch();
}
void display()
{
	cout<<"\n==================================================================";
	cout<<"\n\n==============\tBadhon's Store\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPRODUCTS_NAME\tSTOCK AVAILABLE\t\t\t PRICE";
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
		 getch();
	 	 break;
		}
	    st.show();
	  }
     }
     fin.close();
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
		 getch();
	 	 break;
		}
	     st.sales_show();
	  }
     }
     fin.close();
}
void refill()
{
	system("cls");
	char temp[100];int qty;
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
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 display(); cin.get();
    
	
}
void remove()
{
	system("cls");	
	 int i=0;
     char temp[30];
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
}
void stock::withdraw(int qty)
{
	if(quantity>=qty)
	{
		quantity-=qty;
		sold+=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<price*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();	
}
void stock::refil(int qty)
{	
		quantity+=qty;
		cout<<"\n\nStock updated.";
	    getch();
}
int stock::stock_check(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()
{   
	cout<<"Enter name of the product followed by price and quantity...\n";
	cin>>name>>price>>quantity;
	sold=0;
}
void stock::show()
{
	cout<<"\n"<<name<<"\t\t\t"<<quantity<<"\t\t\t"<<price;

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
	getch();
	system("cls");
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
    if (n!=0)
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

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";

}
}
void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
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
	getch();
}
void display()
{
	cout<<"\n==================================================================";
	cout<<"\n\n==============\tBadhon's Store\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPRODUCTS_NAME\tSTOCK AVAILABLE\t\t\t PRICE";
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
		 getch();
	 	 break;
		}
	    st.show();
	  }
     }
     fin.close();
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
		 getch();
	 	 break;
		}
	     st.sales_show();
	  }
     }
     fin.close();
}
void refill()
{
	system("cls");
	char temp[100];int qty;
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
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 display(); cin.get();
    
	
}
void remove()
{
	system("cls");	
	 int i=0;
     char temp[30];
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
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Sales Report\n6. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
	addnew();getch();
	goto dealermenu;
	}
	else if(i==2)
	{
	system("cls");
	display();getch();goto dealermenu;
	}
	else if(i==3)
	{
		refill();goto dealermenu;
	}
	else if(i==4)
	{
		remove();getch();goto dealermenu;
	}
	else if(i==5)
	{
		sales();getch();goto dealermenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop...";
	getch();
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
	withdraw();getch();goto customermenu;
	}
	else if(i==2)
	{
	system("cls");
	display();getch();goto customermenu;
	}
    else 
	{
	system("cls");
	cout<<"\n\n\n\tThanks for visiting my shop";
	getch();
	exit(0);
}
	}	
	getch();	
}
