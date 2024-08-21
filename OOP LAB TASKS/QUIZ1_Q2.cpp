#include <iostream>
using namespace std;
class point
{
private:
    int x, y;

public:
    point(int i = 0, int j = 0)
    {
        x = i;
        y = j;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
};
int main()
{
    point p1;
    point p2 = p1;
    cout << "x=" << p2.getx() << "y=" << p2.gety();
    return 0;
}