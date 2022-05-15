#include<iostream> 
using namespace std; 
// class 
class Bank  
{     
    public: 
        int accountnumber;     
        char name[50];     
        long balance; 
        virtual void show()=0; 
        
}; 
class account:public Bank 
{     
    public: 
        void OpenAccount() 
    {         
        cout<<"Enter Account Number: ";         
        cin>>accountnumber;         
        cout<<"Enter A Name Of the Account Holder: ";         
        cin>>name;         
        cout<<"Enter A Balance: ";         
        cin>>balance; 
        
    }     
    void ShowAccount() 
    {         
        cout<<"Account Number: "<<accountnumber<<"\n";         
        cout<<"Account Holder Name: "<<name<<"\n";         
        cout<<"Balance: "<<balance<<"\n";       
        cout<<"\n\n"; 
        
    }     
    void show(){}; 
}; 
class operation: public account 
{     
    public: 
        void show(){};     
        void Deposit() 
        {         
            long amount;         
            cout<<"How much amount to be deposit ? ";         
            cin>>amount;         
            balance=balance+amount;         
            account::ShowAccount(); 
            
        }     
        void Withdrawal() 
        {         
            long amount;         
            cout<<"How much amount to be withdraw ? ";         
            cin>>amount;         
            if(amount<=balance) 
            {             
                balance=balance-amount;             
                account::ShowAccount(); 

            }         
            else             
                cout<<"Less Balance "<<endl; 
        }     
        
        int Search(int); 
        
}; 

int operation::Search(int a) 
{     
    if(accountnumber==a) 
        {         
            account::ShowAccount();         
            return(1); 
        } 
    return (0); 
} 
// main code 
int main() 
{     
    int n;     
    cout<<"Enter the number of accounts you want to create: ";     
    cin>>n;     
    operation C[n];     
    int found=0,a,choice,i;     
    for(i=0;i<n;i++)  
    { 
        C[i].OpenAccount(); 
    }     
    
    do  
    { 
        cout<<"\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit"<<"\n"; // display options
        cout<<"Please input your choice: ";   // user input       
        cin>>choice;         
        switch(choice)  
        {             
            case 1: // displaying account info             
                    for(i=0;i<n;i++)  
                    { 
                        C[i].ShowAccount(); 
                    }             
                    break;             
            case 2: // searching the record             
                    cout<<"Enter account number: ";             
                    cin>>a; 
                    for(i=0;i<n;i++)  
                    {                 
                        found=C[i].Search(a);                 
                        if(found)                     
                        break; 
                    }             
                    
                    if(!found)                 
                    cout<<"Record Not Found"<<"\n";             
                    break;             
            case 3: // deposit operation             
                    cout<<"Account Number To Deposit Amount: "; 
                    cin>>a; 
                    for(i=0;i<n;i++)  
                    {                 
                        found=C[i].Search(a);                 
                        if(found)  
                            { 
                                C[i].Deposit();                     
                                break; 
                            }             
                        
                    }             
                    
                    if(!found)                 
                        cout<<"Record Not Found"<<"\n";             
                        break;             
            case 4: // withdraw operation             
                    cout<<"Account Number To Withdraw Amount?";             
                    cin>>a; 
                    for(i=0;i<n;i++)  
                    {                 
                        found=C[i].Search(a);                 
                        if(found)  
                        { 
                            C[i].Withdrawal();                     
                            break; 
                        }             
                        
                    }             
                    
                    if(!found)                 
                        cout<<"Record Not Found"<<"\n";             
                        break;             
                case 5: // exit             
                        cout<<"Have a nice day! "<<"\n";             
                        break;             
                default : 
                        cout<<"Wrong Option"<<"\n"; 
        }     
        
    }while(choice!=5);     
    
    return 0; 
} 
 
