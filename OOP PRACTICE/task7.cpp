#include <iostream>
using namespace std;
class Example
{
    int val;

public:
    Example(int x)
    {
        val = x;
    }
    Example add(Example E1, Example E2)
    {
        Example E3(E1.val + E2.val + val);
        return E3;
    }
    void display()
    {
        cout << "Value: " << val << endl;
    }
};
int main()
{
    Example object1(1), object2(2), object3(0);
    object3 = object3.add(object1,object2);
    object1.display();
    object2.display();
    object3.display();
    return 0;
}
