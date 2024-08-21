#include <iostream>
using namespace std;
class MyClass
{
public:
    int a;
    void add(const MyClass &obj)
    {
        a += obj.a;
    }
};
int main()
{
    MyClass obj1, obj2;
    obj1.a = 5;
    obj2.a = 10;
    obj1.add(obj2);
    cout << obj1.a;
    return 0;
}
