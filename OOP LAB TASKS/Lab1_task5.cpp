#include <iostream>
using namespace std;
int Perimetercalculate(int l, int w)
{
    return 2 * (l + w);
}

int Areacalculate(int l, int w)
{
    return l * w;
}

int main()
{
    int l, w, P, A;
    cout << "Enter the Length of Rectangle: ";
    cin >> l;
    cout << "Enter the width of Rectangle: ";
    cin >> w;
    P = Perimetercalculate(l, w);
    A = Areacalculate(l, w);
    cout << "Perimeter of Rectangle: " << P << endl;
    cout << "Area of Rectangle : " << A;
    return 0;
}
