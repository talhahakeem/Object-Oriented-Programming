#include <iostream>
using namespace std;
class Test
{
private:
    const int i;

public:
    Test(int x) : i(x) {}
    void display()
    {
        cout << "Value of i is:" << i;
    }
};
int main()
{
    Test t1(5);
    t1.display();
    return 0;
}