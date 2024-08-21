#include <iostream>
using namespace std;
class Number
{
private:
    int x, y;

public:
    Number()
    {
        x = y = 100;
    }
    void avg()
    {
        cout << "x= " << x << endl;
        cout << "Y= " << y << endl;
        cout << "Average= " << (x + y) / 2;
    }
};
int main()
{

    Number n;
    n.avg();
    return 0;
}