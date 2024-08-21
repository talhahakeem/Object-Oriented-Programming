#include <iostream>
using namespace std;
bool is_prime(int n)
{
    bool is_prime = true;
    if (n == 0 || n == 1)
    {
        is_prime = false;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}
int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (is_prime(n))
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
