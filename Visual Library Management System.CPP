#include <iostream>
#include <conio.h>
using namespace std;

void getAccountDetails();
void editAccountDetails();
void getSubscription();
void cancelSubscription();
void showAccountDetails();
void checkEmail();
void showSubDetails();
void menu();
int n;

//------------------------------Library Class------------------------------

class Library{
	int bnum;
	string bname,author,pub;
	int copies;
	int copies_issued;
public:
	float price;
	int libflag=0;
	void initial(){
		cout<<"\nEnter Book Number: ";
		cin>>bnum;
		cout<<"Enter Book Name: ";
		cin.ignore();
		getline(cin,bname);
		cout<<"Enter Author Name: ";
		getline(cin,author);
		cout<<"Enter Publisher Name: ";
		getline(cin,pub);
		cout<<"Enter price of the book: ";
		cin>>price;
		cout<<"Enter number of copies of the book: ";
		cin>>copies;
	}
	void issueBook(){
		cout<<"\nEnter details:-\n";
		initial();
		if(copies>0){
			cout<<"Enter how many copies you want to issue: ";
			cin>>copies_issued;
			if(copies>=copies_issued){
				copies=copies-copies_issued;
				cout<<"\n"<<copies_issued<<" book(s) are issued.";
				libflag=1;
				//display();
			}
			else
				cout<<"\n"<<copies_issued<<" books are not available in stock.";
		}
		else
			cout<<"Entered book is not available for sale.";
	}
	void showLibDetails(){
			cout<<"\n\nBOOK ISSUED:";
		if(libflag==1){
			cout<<"\nBook Number: "<<bnum;
			cout<<"\nBook Name: "<<bname;
			cout<<"\nAuthor Name: "<<author;
			cout<<"\nPublisher Name: "<<pub;
			cout<<"\nPrice: Rs. "<<price;
			cout<<"\nNumber of copies issued: "<<copies_issued;
		}
		else
			cout<<" None\n";
	}
	void returnBook(){
		char c;
		cout<<"\nThe following book was issued to your account:";
		cout<<"\nBook Number: "<<bnum;
		cout<<"\nBook Name: "<<bname;
		cout<<"\nNumber of copies issued: "<<copies_issued;
		cout<<"\nProceed to return the book? (Y/N) :> ";
		cin>>c;
		while(c!='y' && c!='Y' && c!='n' && c!='N'){
			cout<<"Incorrect response, please try again :> ";
			cin>>c;
		}
		if(c=='y' || c=='Y'){
			copies=copies+copies_issued;
			cout<<"\n"<<bnum<<" : "<<bname<<" : Book is returned.";
			libflag=0;
		}
		else
			cout<<"\nReturn cancelled...\n";
	}
};

//-------------------------Subscription Class-------------------------

class Subscription{
	string status="Inactive (None)",upi;
	int plan;
public:
	int subflag=0,amt=0,bankaccount;
	void getSubscription(){
		cout<<"\nChoose one of the following subscription plans :";
		cout<<"\n[1] 1 Year   @ Rs. 1899";
		cout<<"\n[2] 6 Months @ Rs. 999";
		cout<<"\n[3] 1 Month  @ Rs. 199";
		cout<<"\n[4] Back to Menu";
		cout<<"\nEnter your choice (1-4):> ";
		cin>>plan;
		while(plan<1 || plan>4){
			cout<<"Incorrect response, please try again :> ";
			cin>>plan;
		}
		if(plan==1){
			status="Active (1 Year @ Rs. 1899)";
			amt=1899;
			subflag=1;
		}
		else if(plan==2){
			status="Active (6 Months @ Rs. 999)";
			amt=999;
			subflag=1;
		}
		else if(plan==3){
			status="Active (1 Month @ Rs. 199)";
			amt=199;
			subflag=1;
		}
		else if(plan==4){
			status="Inactive (None)";
			amt=0;
			subflag=0;
		}
		if(subflag==1){
			cout<<"\nSubscription plan issued and activated.";
			cout<<"\nAmount Paid : Rs. "<<amt;
		}
		else{
			cout<<"\nNo Subscription plan issued.";
			cout<<"\nPlease purchase one to get access to the Library.";
		}
	}
	void cancelSubscription(){
		cout<<"\nWould you like to cancel your subscription plan?";
		cout<<"\n[1] Cancel Subscription @ 70% Cashback";
		cout<<"\n[2] Back to Menu";
		cout<<"\nEnter your choice (1-2):> ";
		cin>>n;
		while(n!=1 && n!=2){
			cout<<"Incorrect response, please try again :> ";
			cin>>n;
		}
		if(n==1){
			subflag=0;
			cout<<"\nYour subscription plan has been cancelled.";
			cout<<"\nRs. "<<amt*0.7<<" will be transacted to your preferred bank account.";
			cout<<"\n[1] UPI";
			cout<<"\n[2] Debit Card";
			cout<<"\nEnter your choice (1-2):> ";
			cin>>n;
			while(n!=1 && n!=2){
				cout<<"Incorrect response, please try again :> ";
				cin>>n;
			}
			if(n==1){
				cout<<"Enter your UPI ID: ";
				cin>>upi;
				cout<<"\nRefund Succesfull!";
			}
			else if(n==2){
				int bacn;
				cout<<"Enter your Bank Account Number : ";
				cin>>bacn;
				while(bacn!=bankaccount){
					cout<<"\nYour entered account number doesn't match!";
					cout<<"\nEnter correct details or update your linked number!";
					cout<<"\nPlease enter again :> ";
					cin>>bacn;
				}
				cout<<"\nRefund Succesfull!";
				status="Inactive (None)";
				amt=0;
			}
		}
	}
	void showSubDetails(){
		cout<<"\n\nYOUR SUBSCRIPTION DETAILS :";
		cout<<"\nSubscription Status (Plan) : "<<status;
		cout<<"\nAmount Paid : Rs. "<<amt;
	}
};

//------------------------------Account Class------------------------------

class Account: public Library,public Subscription{
	string name,email;
public:
	int accnum=2001;
	void checkEmail(){
		int At=-1,Atfr=0,Dot=-1,sp=0,alfr=0,j=email.length();
		for(int i=0;i<j;i++){
			if(email[i]=='@'){
				At=i;
				Atfr++;
			}
			else if(email[i]=='.')
				Dot=i;
			else if((email[i]>31 && email[i]<48 && email[i]!=46)
					|| (email[i]>57 && email[i]<64)
					|| (email[i]>90 && email[i]<97)
					|| (email[i]>122 && email[i]<127))
				sp=1;
			else if((email[i]>64 && email[i]<91)
					|| (email[i]>96 && email[i]<123))
				alfr++;
		}
		if(At==-1 || Dot==-1 || At==0 || Dot==0 || Dot==j-1 ||
			At==j-1 || At>Dot || Dot-At<2 || Atfr>1 || sp==1 || alfr<5){
			cout<<"\nError! Invalid Email Address.";
			cout<<"\nPlease Enter again : ";
			getline(cin,email);
			checkEmail();
		}
	}
	void getAccountDetails(){
		cout<<"\nEnter details for Account Number-"<<accnum;
		cout<<"\nEnter your User Name : ";
		//cin.ignore();
		getline(cin,name);
		cout<<"Enter your Email ID : ";
		//cin.ignore();
		getline(cin,email);
		checkEmail();
		cout<<"Enter your Bank Account Number : ";
		cin>>bankaccount;
		cout<<"\nAccount created...\n";
	}
	void editAccountDetails(){
		cout<<"\nWhat would you like to change?";
		cout<<"\n[1] Your User Name : "<<name;
		cout<<"\n[2] Your Email ID : "<<email;
		cout<<"\n[3] Your Bank Account Number : "<<bankaccount;
		cout<<"\n[4] All the details";
		cout<<"\n[5] Back to Menu\n";
		cout<<"\nEnter your choice (1-5):> ";
		cin>>n;
		while(n<1 || n>4){
			cout<<"Incorrect response, please try again :> ";
			cin>>n;
		}
		if(n==1){
			cout<<"\nEnter a new User Name : ";
			//cin.ignore();
			getline(cin,name);
			cout<<"\nYour User Name has been updated.";
		}
		else if(n==2){
			cout<<"\nEnter a new Email ID : ";
			//cin.ignore();
			getline(cin,email);
			checkEmail();
			cout<<"\nYour Email Address has been updated.";
		}
		else if(n==3){
			cout<<"\nEnter a new Bank Account Number : ";
			cin>>bankaccount;
			cout<<"\nYour linked Bank Account Number has been updated.";
		}
		else if(n==4){
			cout<<"\nEnter a new User Name : ";
			cin.ignore();
			getline(cin,name);
			cout<<"\nEnter a new Email ID : ";
			//cin.ignore();
			getline(cin,email);
			checkEmail();
			cout<<"\nEnter a new Bank Account Number : ";
			cin>>bankaccount;
			cout<<"\nYour Account details have been updated.";
		}
	}
	void showAccountDetails(){
		cout<<"\nYOUR ACCOUNT DETAILS :";
		cout<<"\nUser Name : "<<name;
		cout<<"\nEmail ID : "<<email;
		cout<<"\nAccount Number : "<<accnum;
		cout<<"\nBank Account Number : "<<bankaccount;
		showSubDetails();
		showLibDetails();
	}
};

//----------------------------Global Object---------------------------

Account Ac;

//----------------------------Menu Function----------------------------
void menu(){
	cout<<"\nPress ENTER to continue...\n";
	getch();
	system("cls");
	cout<<"----Virtual Library----";
	cout<<"\n\tMenu :";
	cout<<"\n[1] Edit your account";
	cout<<"\n[2] Get a subscription";
	cout<<"\n[3] Cancel subscription";
	cout<<"\n[4] Show Account Details";
	cout<<"\n[5] Issue a book";
	cout<<"\n[6] Return a book";
	cout<<"\n[7] Exit";
	cout<<"\nEnter your choice (1-7):> ";
	cin>>n;
	while(n<1 || n>7){
		cout<<"Incorrect response, please try again :> ";
		cin>>n;
	}
	if(n==1){
		Ac.editAccountDetails();
		menu();
	}
	else if(n==2){
		if(Ac.subflag==0)
			Ac.getSubscription();
		else{
			cout<<"\nA Subscription plan is already activated for your account!";
			Ac.showSubDetails();
		}
		menu();
	}
	else if(n==3){
		if(Ac.subflag==1)
			Ac.cancelSubscription();
		else
			cout<<"\nYou don't have an active Subscription Plan!";
		menu();
	}
	else if(n==4){
		Ac.showAccountDetails();
		menu();
	}
	else if(n==5){
		if(Ac.libflag==0 && Ac.subflag==1)
			Ac.issueBook();
		else if(Ac.libflag==1)
			cout<<"\nA book is already issued. Return it in order to issue another.";
		else if(Ac.subflag==0)
			cout<<"\nYou don't have an active Subscription Plan!";
		menu();
	}
	else if(n==6){
		if(Ac.libflag==1)
			Ac.returnBook();
		else
			cout<<"\nThere is no issued book in your account, that you have to return.";
		menu();
	}
	else
		cout<<"\nProgram terminated...\n\n";
}
int main(){
	char c;
	cout<<"Welcome to the Virtual Library!";
	cout<<"\nPlease create an account first:-\n";
	Ac.getAccountDetails();
	cout<<"\nWould you like to buy a subscription? (Y/N): ";
	cin>>c;
	while(c!='y' && c!='Y' && c!='n' && c!='N'){
		cout<<"Incorrect response, please try again :> ";
		cin>>c;
	}
	if(c=='y' || c=='Y')
		Ac.getSubscription();
	menu();
	return 0;
}
