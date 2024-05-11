#include <iostream>
#include <string>
using namespace std;

class BankAccount {

    private:
        int balance;
    public:

        BankAccount(int initBalance) : balance {initBalance} { cout<<"constructor"<<endl;}
        int getBalance () const{ return this->balance;}

        // const BankAccount* const this
        BankAccount operator+(const BankAccount & operandTwo) const {

            cout<<"operator overloading"<< endl;
            BankAccount newAccount(0);
            newAccount.balance = this->balance+ operandTwo.getBalance();
            return newAccount;
        }

        ~BankAccount() {cout<<"destructor"<<endl;}

        friend ostream& operator<<(ostream& out, const BankAccount & operandTwo) {
            out<<" current balance is" << operandTwo.balance;
            return out;
            // we can't use this because this is not explicitly passed in the function
            // because this is not object level function.

            //we can access private members also because it's a friend function.

        }
};

int main()
{
    BankAccount acc1(1000);
    BankAccount acc2(2000);
    cout<< acc1 <<endl;
    cout<< acc2<<endl;
    
    BankAccount acc3 = acc1 + acc2;
    cout<< acc3.getBalance()<<endl;
}