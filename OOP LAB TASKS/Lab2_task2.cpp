#include <iostream>
using namespace std;

class account
{
public:
    string name;
    int account_number;
    float balance;
    void inputdata()
    {
        cout << "Enter the name : ";
        cin >> name;
        cout << "Enter account number : ";
        cin >> account_number;
        cout << "Enter balance : ";
        cin >> balance;
    }
    void display_data()
    {
        cout << "your name is : " << name << endl;
        cout << "your account number is : " << account_number << endl;
        cout << "your balance : " << balance << endl;
    }
    void withdraw()
    {
        int withdraw;
        cout << "Enter amount you wants to withdraw : ";
        cin >> withdraw;
        if (withdraw <= balance)
        {
            balance = balance - withdraw;
            cout << "Your remaining balance : " << balance << endl;
        }
        else
        {
            cout << "Sorry!Your Account balance is Low.\n";
        }
    }
    void deposit_money()
    {
        int deposit;
        cout << "Enter amount you wants to deposit : ";
        cin >> deposit;
        balance = balance + deposit;
        cout << "Balance after depositing : " << balance << endl;
    }
};

int main()
{
    int choice;
    account bank;
    bank.inputdata();
    do
    {
        cout << "Enter the choice from following:\n ";
        cout << "press 1 for amount deposit:\n";
        cout << "press 2 for amount withdraw:\n";
        cout << "press 3 for data display:\n";
        cout << "press 4 to Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            bank.deposit_money();
            break;
        }
        case 2:
        {
            bank.withdraw();
            break;
        }
        case 3:
        {
            bank.display_data();
            break;
        }
        case 4:
        {
            cout << "You Exist sucessfully.";
            break;
        }
        default:
        {
            cout << "please Enter the valid choice: ";
            break;
        }
        }
    } while (choice != 4);
    return 0;
}