#include<iostream>
using namespace std;
class digitalaccount
{
private:
    string name;
    int accountID;
    double balance;
public:
    digitalaccount(){
        name="";
        accountID=0;
        balance=0;
    }
    void createAccount(){
        cout<<"Enter Customer Name:";
        cin>>name;
        cout<<"Enter Account ID:";
        cin>>accountID;
        cout<<"Enter Initial Balance:";
        cin>>balance;
        if(balance<0){
            balance=0;
            cout<<"Negative balance not allowed. Balance set to 0.\n";
        }
        cout<<"Account created successfully!\n";
    }
    void deposit(){
        double amount;
        cout<<"Enter amount to deposit:";
        cin>>amount;
        if(amount>0){
            balance=balance+amount;
            cout<<"Deposit successful!\n";
        }
        else{
            cout<<"Invalid deposit amount!\n";
        }
    }
    void withdraw(){
        double amount;
        cout<<"Enter amount to withdraw:";
        cin>>amount;
        if(amount<=0){
            cout<<"Invalid withdrawal amount\n";
        }
        else if(amount>balance)
            {
            cout<<"Insufficient balance Withdrawal failed.\n";
        }
        else{
            balance=balance-amount;
            cout<<"Withdrawal successful\n";
        }
    }
    void display(){
        cout<<"Customer Name:"<<name<<endl;
        cout<<"Account ID:"<<accountID<<endl;
        cout<<"Current Balance:"<<balance<<endl;
    }
    int getID(){
        return accountID;
    }
};

int main(){
    digitalaccount accounts[5];
    int count=0;
    int choice,id,found;
    while(true)
        {
        cout<<"1. Create Account\n";
        cout<<"2. Deposit Money\n";
        cout<<"3. Withdraw Money\n";
        cout<<"4. Display Account Details\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            if(count<5)
                {
                accounts[count].createAccount();
                count++;
            }
            else
                {
                cout<<"Account limit reached!\n";
            }
            break;
        case 2:
            cout<<"Enter Account ID:";
            cin>>id;
            found=0;
            for(int i=0;i<count;i++){
                if(accounts[i].getID()==id)
                    {
                    accounts[i].deposit();
                    found=1;
                }
            }
            if(found==0)
                cout<<"Account not found!\n";
            break;
        case 3:
            cout<<"Enter Account ID:";
            cin>>id;
            found=0;
            for(int i=0;i<count;i++)
                {
                if(accounts[i].getID()==id)
                {
                    accounts[i].withdraw();
                    found=1;
                }
            }
            if(found==0)
                {
                    cout<<"Account not found\n";
                    }
            break;
        case 4:
            cout<<"Enter Account ID:";
            cin>>id;
            found=0;
            for(int i=0;i<count;i++)
                {
                if(accounts[i].getID()==id)
                {
                    accounts[i].display();
                    found=1;
                }
            }
            if(found==0)
                cout<<"Account not found\n";
            break;
        case 5:
            cout<<"Exiting program";
            return 0;
        default:
            cout<<"Invalid choice. Try again.\n";
        }
    }
    return 0;
}
