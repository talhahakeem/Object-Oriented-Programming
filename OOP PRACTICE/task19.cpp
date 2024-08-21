#include <iostream>
using namespace std;
class BankAccount {
private:
 const int account_number;
 static int num_accounts;
public:
 BankAccount(int acc_num) : account_number(acc_num) {
 num_accounts++;
 }
 static int getNumAccounts() {
 return num_accounts;
 }
};
int BankAccount::num_accounts = 0;
int main() {
 BankAccount acc1(1001);
 BankAccount acc2(1002);
 BankAccount acc3(1003);
 cout << "Total number of accounts: " << BankAccount::getNumAccounts() << endl;
 return 0;
}
