#include <iostream>
using namespace std;
void sortingnum(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
int main()
{
    int A[2];
    cout << "Enter the two numbers: ";
    for (int i = 0; i < 2; i++)
    {
        cin >> A[i];
    }
    sortingnum(A, 2);
    cout << "Sorted Two numbers are: ";
    for (int i = 0; i < 2; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}