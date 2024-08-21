#include <iostream>
using namespace std;
int main()
{
    int A[2];
    cout << "Enter the two numbers: ";
    for (int i = 0; i < 2; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 2; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    cout << "Sorted Two numbers are: ";
    for (int i = 0; i < 2; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}