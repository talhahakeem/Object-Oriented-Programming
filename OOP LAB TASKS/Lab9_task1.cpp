#include<iostream>
using namespace std;
class Mathoperations
{
    protected:
    double a,b,c;
    public:
        int sum(int a,int b)
    {
        return a+b;
    }
       int subtract(int a,int b)
    {
        return a-b;
    }
    int multiply(int a,int b)
    {
        return a*b;
    }
    int divis(int a,int b)
    {
        if (a==0)
        {
            cout<<"Division is impossible.";
        }
        else
        {
            return a/b;
        } 
    }
};
class Addition:public Mathoperations
{
    public:
    int sum(int a,int b,int c)
    {
        return a+b+c;
    }
 double sum(double a,double b)
    {
        return a+b;
    }
    double sum(double a,double b,double c)
    {
        return a+b+c;
    }
};
class Subtraction:public Mathoperations
{
    public:
    int subtract(int a,int b,int c)
    {
        return a-b-c;
    }
 double subtract(double a,double b)
    {
        return a-b;
    }
    double subtract(double a,double b,double c)
    {
        return a-b-c;
    }
};
class multiplication:public Mathoperations
{
    public:
    int multiply(int a,int b,int c)
    {
        return a*b*c;
    }
 double multiply(double a,double b)
    {
        return a*b;
    }
    double multiply(double a,double b,double c)
    {
        return a*b*c;
    }
};
class division:public Mathoperations
{
    public:
 double divis(double a,double b)
    {
        return a/b;
    }
};
int main()
{
    Addition add;
    Subtraction sub;
    multiplication mul;
    division div;
    add.sum(4,5);
    add.sum(4,5,6);
    add.sum(4.50,5.50);
    add.sum(4.50,7.80,2.50);
    sub.subtract(9,6);
    sub.subtract(9,8,7);
    sub.subtract(4.50,5.50);
    sub.subtract(4.50,7.80,5.60);
    mul.multiply(4,5);
    mul.multiply(9,8,7);
    mul.multiply(4.50,5.50);
    mul.multiply(4.50,7.80,5.60);
    div.divis(10,5);
    div.divis(50.60,5.20);
    return 0;
}