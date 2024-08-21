#include<iostream>
using namespace std;
class counter
{
    private:
    int count;
    public:
    counter()
    {
        count=0;
    }
    counter(int c)
    {
        count=c;
    }
    int get_count()
    {
        return count;
    }
    counter operator++()
    {
        ++count;
        // return counter(++count);
        counter temp;
        temp.count=count;
        return temp;
    }
    counter operator++(int)
    {
        count++;
        counter temp;
        temp.count=count;
        return temp;
        // return counter(count++);
    }
};
int main()
{
    counter c1,c2;
    cout<<"Value of C1: "<<c1.get_count()<<endl;
    cout<<"Value of C2: "<<c2.get_count()<<endl;
    ++c1;
    c2=++c1;
    cout<<"Value of C1: "<<c1.get_count()<<endl;
    cout<<"Value of C2: "<<c2.get_count()<<endl;
    c2=c1++;
    cout<<"Value of C1: "<<c1.get_count()<<endl;
    cout<<"Value of C2: "<<c2.get_count()<<endl;

    return 0;
}