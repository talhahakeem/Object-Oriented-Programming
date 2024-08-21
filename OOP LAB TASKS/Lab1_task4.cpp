#include <iostream>
using namespace std;
int main()
{
    int l, w, P, A;
    cout << "Enter the Length of Rectangle: ";
    cin >> l;
    cout << "Enter the width of Rectangle: ";
    cin >> w;
    P = 2 * (l + w);
    A = l * w;
    cout << "Perimeter of Rectangle: " << P << endl;
    cout << "Area of Rectangle : " << A;
    return 0;
}