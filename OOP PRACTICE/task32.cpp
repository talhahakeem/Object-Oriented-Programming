#include<iostream>
using namespace std;
class A
{
    public:
    int a;
    void f1()
    {
        cout<<"F1 is called.";
    }
};
class B:virtual public A
{
    public:
    int b;
    void f2()
    {
        cout<<"F2 is called.";
    }
};
class C:virtual public A
{
    public:
    int c;
    void f3()
    {
        cout<<"F3 is called.";
    }
};
class D:public B,public C
{
    public:
    int e;
    void f4()
    {
        cout<<"F4 is called.";
    }
};
int main()
{
    D d;
    d.f4();
    cout<<endl;
    d.f3();
    cout<<endl;
    d.f2();
    cout<<endl;
    d.f1();
    cout<<endl;
    d.a=5;
    cout<<d.a<<endl;
    d.b=10;
    cout<<d.b<<endl;
    d.c=15;
    cout<<d.c<<endl;
    d.e=20;
    cout<<d.e<<endl;
    cout<<d.e<<endl;
    d.a=10;
    cout<<d.a<<endl;
    d.b=15;
    cout<<d.b<<endl;
    return 0;
}