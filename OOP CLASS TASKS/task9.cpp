#include<iostream>
using namespace std;
class Myclass
{
    private:
    int data;
    public:
    Myclass(int d):data(d){}
    void display()
    {
        cout<<"Data:"<<data<<endl;
    }
};
int main()
{
    Myclass *ptr=new Myclass(10);
    ptr->display();
    delete ptr;
    ptr->display();
    return 0;
}