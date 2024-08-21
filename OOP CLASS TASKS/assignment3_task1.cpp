#include<iostream>
using namespace std;
class myClass
{
private:
    int value;
public:
    myClass(int val)
    {
        value = val;
    }
    int operator+(int b)
    {
        return value + b;
    }
};
int main()
{
    int b = 5;
    myClass object(10);
    int a = object + b;
    cout << "Result: " << a << endl;
    return 0;
}