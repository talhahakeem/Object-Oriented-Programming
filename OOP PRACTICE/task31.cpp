#include<iostream>
using namespace std;
class ThreeD
{
    int x,y,z;
    public:
    ThreeD()
    {
        x=y=z=0;
    }
    ThreeD(int i,int j,int k)
    {
        x=i;
        y=j;
        z=k;
    }
    ThreeD operator-(ThreeD obj2)
    {
        ThreeD temp;
        temp.x=x-obj2.x;
        temp.y-=y-obj2.y;
        temp.z=z-obj2.z;
        return temp;
    }
    ThreeD operator+(ThreeD obj2)
    {
        ThreeD temp;
        temp.x=x+obj2.x;
        temp.y-=y+obj2.y;
        temp.z=z+obj2.z;
        return temp;
    }
    ThreeD operator=(ThreeD obj2)
    {
        x=obj2.x;
        y=obj2.y;
        z=obj2.z;
        return *this;
    }
    void show()
    {
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
};
int main()
{
    ThreeD a(1,2,3),b(10,10,10),c;
    cout<<"Orignal Values of a: ";
    a.show();
    cout<<"Orignal Values of b: ";
    b.show();
    c=b-a;
    cout<<"b-a:";
    c.show();
    return 0;
}