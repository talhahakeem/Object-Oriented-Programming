#include <iostream>
using namespace std;
class Rectangle
{
private:
    double length;
    double breadth;
public:
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    }
    Rectangle(double s)
    {
        length = s;
        breadth = s;
    }
    double calculateArea()
    {
        return length * breadth;
    }
};
int main()
{
    Rectangle rect1;
    Rectangle rect2(4, 5);
    Rectangle rect3(6);
    cout << "Area of rectangle with no parameters: " << rect1.calculateArea() << endl;
    cout << "Area of rectangle with two parameters: " << rect2.calculateArea() << endl;
    cout << "Area of rectangle with one parameter: " << rect3.calculateArea() << endl;
    return 0;
}
