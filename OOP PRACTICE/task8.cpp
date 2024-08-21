#include <iostream>
using namespace std;

bool isPrime(int num)
{
    int count = 0;
    for (int j = 1; j <= num; j++)
    {
        if (num % j == 0)
        {
            count++;
        }
    }
    return (count == 2);
}
int main()
{
    int i;
    cout << "Enter number:";
    cin >> i;
    if (isPrime(i))
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not prime";
    }
    return 0;
}
