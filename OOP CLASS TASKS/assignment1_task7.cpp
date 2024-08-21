#include <iostream>
using namespace std;
class Triangle
{
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3)
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
    void isEquilateral()
    {
        if (side1 == side2 && side2 == side3)
        {
            cout << "The triangle is equilateral.\n";
        }
    }
    void isIsosceles()
    {
        if (side1 == side2 || side1 == side3 || side2 == side3)
        {
            cout << "The triangle is isosceles.\n";
        }
    }
    void isScalene()
    {
        if (side1 != side2 && side1 != side3 && side2 != side3)
        {
            cout << "The triangle is scalene.\n";
        }
    }
};

int main()
{
    double side1, side2, side3;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> side1 >> side2 >> side3;
    Triangle t(side1, side2, side3);
    t.isEquilateral();
    t.isIsosceles();
    t.isScalene();
    return 0;
}
