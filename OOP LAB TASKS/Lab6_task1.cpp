#include <iostream>
using namespace std;
class base
{
    int num1;

public:
    int num2;
    void getdata()
    {
        num1 = 10;
        num2 = 20;
    }
    void display()
    {
        cout << num1 << " ";
        cout << num2 << endl;
    }
};
class derived : private base
{
    int num3;

public:
    void get()
    {
        num2 = 30;
        num3 = 40;
    }
    void disp()
    {
        cout << num2 << " ";
        cout << num3 << endl;
    }
};
int main()
{
    base d;
    d.getdata();
    d.display();
    derived b;
    b.get();
    b.disp();
    return 0;
}