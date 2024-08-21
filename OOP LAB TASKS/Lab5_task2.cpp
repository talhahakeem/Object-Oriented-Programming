#include <iostream>
using namespace std;

class triangle
{
private:
    double height;
    double base;

public:
    triangle(double h, double b)
    {
        height = h;
        base = b;
    }
    void setheight(double x)
    {
        height = x;
    }
    void getheight()
    {
        cout << "Height is :" << height << endl;
    }
    void setbase(double x)
    {
        base = x;
        cout << "Base is :" << base;
    }
};

int main()
{
    triangle t1(89.09, 34.6);
    cout << endl;
    t1.setheight(45.89);
    t1.getheight();
}