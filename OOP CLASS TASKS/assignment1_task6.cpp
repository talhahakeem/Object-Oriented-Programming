#include <iostream>
using namespace std;
class BankAccount
{
private:
    int accountNumber;
    double balance;
public:
    BankAccount(int acc_Number, double initialBalance)
    {
        accountNumber = acc_Number;
        balance = initialBalance;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }
    void display()
    {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};
int main()
{
    BankAccount account(56789, 500000);
    account.display();
    account.deposit(200000);
    account.display();
    account.withdraw(300000);
    account.display();
    return 0;
}
