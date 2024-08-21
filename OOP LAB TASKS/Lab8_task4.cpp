#include <iostream>
using namespace std;
class Shape
{
public:
    void draw_shape()
    {
        cout << "This is a generic shape." << endl;
    }
};
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }
    void draw_circle()
    {
        cout << "Circle with radius: " << radius << endl;
    }
};
class Square : public Shape
{
private:
    float side;

public:
    Square(float s)
    {
        side = s;
    }
    void draw_square()
    {
        cout << "Square with side: " << side << endl;
    }
};
int main()
{
    Circle circle(5.0);
    Square square(4.0);
    circle.draw_circle();
    square.draw_square();
    return 0;
}
