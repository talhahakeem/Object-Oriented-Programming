#include<iostream>
using namespace std;
class myClass
{
    int data;
public:
    myClass(int val)
    { 
        data = val;
    }
    int operator+ (myClass &a)
    { 
        return data + a.data; 
    }
};
int main()
{
    myClass object1(5), object2(10);
    int a = object1 + object2;
    cout << "Result: " << a << endl;
    return 0;
}