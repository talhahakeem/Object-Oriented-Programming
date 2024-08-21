#include <iostream>
using namespace std;
int maximum(int *arr, int size)
{
    int max = *arr;
    for (int *ptr = arr; ptr != arr + size; ptr++)
    {
        if (*ptr > max)
        {
            max = *ptr;
        }
    }
    return max;
}
int oddSwap(int *x, int *y)
{
    int temp = *x;
    *x = *y * 5;
    *y = temp * 5;
    return *x + *y;
}
int *expand(int *arr, int size)
{
    int *new_arr = new int[size * 2];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    for (int i = size; i < size * 2; i++)
    {
        new_arr[i] = -1;
    }
    return new_arr;
}
int *concatenate(int *arr1, int size1, int *arr2, int size2)
{
    int size = size1 + size2;
    int *new_arr = new int[size];
    for (int i = 0; i < size1; i++)
    {
        new_arr[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        new_arr[size1 + i] = arr2[i];
    }
    return new_arr;
}
int main()
{
    int n, m;
    cout << "MAXIMUM VALUE FINDING IN ARRAY: \n";
    cout << "Enter the Size of the Array: ";
    cin >> n;
    int A[n];
    cout << "Enter the Elements of  Array :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "MAXIMUM VALUE in Array Is: " << maximum(A, n) << endl;
    cout << "SWAPING OF TWO VALUES OF VARIABELS: \n";
    int x, y;
    cout << "Enter the Value of two Varibles: \n";
    cin >> x >> y;
    cout << "Before oddSwap: x = " << x << ", y = " << y << endl;
    oddSwap(&x, &y);
    cout << "After oddSwap: x = " << x << ", y = " << y << endl;
    cout << "EXPANDING THE ARRAY: \n";
    cout << "Enter the Size of the Array you want to expand: ";
    cin >> n;
    cout << "Enter the Elements of the Array you want to expand : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int *expandedArr = expand(A, n);
    cout << "Expanded array: ";
    for (int i = 0; i < n * 2; i++)
    {
        cout << expandedArr[i] << " ";
    }
    cout << endl;
    delete[] expandedArr;
    cout << "CONCATENATE THE ARRAYS: \n";
    cout << "Enter the Size of the First Array: ";
    cin >> n;
    cout << "Enter the Elements of the First Array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "Enter the Size of the Second Array:  ";
    cin >> m;
    int B[m];
    cout << "Enter the Elements of the Second Array : \n";
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    int *concatenatedArr = concatenate(A, n, B, m);
    cout << "Concatenated array: ";
    for (int i = 0; i < n + m; i++)
    {
        cout << concatenatedArr[i] << " ";
    }
    cout << endl;
    delete[] concatenatedArr;
    return 0;
}
