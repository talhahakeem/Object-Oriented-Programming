#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int gcd;
    if (a <= 0 || b <= 0)
    {
        return 0;
    }
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int main()
{
    int num1, num2;
    cout << "Enter the Two numbers: ";
    cin >> num1 >> num2;
    int result = gcd(num1, num2);

    if (result != 0)
    {
        cout << "The GCD of " << num1 << " and " << num2 << " is " << result << endl;
    }
    else
    {
        cout << "Error. Both numbers should be positive." << endl;
    }
    return 0;
}
