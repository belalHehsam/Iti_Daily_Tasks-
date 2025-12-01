#include <iostream>

using namespace std;

class BankAccount {

    private:
       string accountHolder ;
       int balance;
       int accountNumber;
    public:
        static int nextID;
        static int counter;

        BankAccount(){
        cout<<"The Default Constructor called"<<endl;
        accountHolder="name";
        balance=0;
        nextID++;
        accountNumber=nextID;
        counter++;
       }

       BankAccount(string s,int value){
        cout<<"The Parameterized  Constructor called"<<endl;
        accountHolder=s;
        balance=value;
        accountNumber= ++nextID;
        counter++;
       }

       BankAccount& deposit(int amount){
            balance += amount;
            return *this;
       }

       BankAccount& withdraw (int amount){

           if (balance >= amount)
                balance -= amount;
           else
                cout << "Insufficient balance!" << endl;
            return *this;
       }

        void showAccount(){
            cout<<"The Name is : "<<accountHolder<<endl;
            cout<<"The Balance is : "<<balance<<endl;
            cout<<"The Account Number is : "<<accountNumber<<endl;
        }

        int getBalance(){
            return balance;
        }

        static void showCounter(){
            cout<<"The Numbers Of Objects is : "<< counter<<endl;
        }

        ~BankAccount()
        {
            cout<<"The Destructor called"<<endl;
        }

};
int BankAccount::counter=0;
int BankAccount::nextID=0;

int main()
{
    BankAccount acc1("Belal", 1000);
    acc1.deposit(500).withdraw(300).showAccount();

    BankAccount acc2;
    acc2.deposit(200).showAccount();

    BankAccount::showCounter();

    return 0;
}
