#include <iostream>
using namespace std;
class time
{
private:
    int h, m, s;

public:
    time()
    {
        h = m = s = 0;
    }
    time(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
    }
    void display()
    {
        cout << h << ":" << m << ":" << s;
    }
    void add(time t1, time t2)
    {
        time t;
        h = t1.h + t2.h;
        m = t1.m + t2.m;
        s = t1.s + t2.s;
    }
};
int main()
{
    time s1(1, 6, 8);
    time s2(5, 7, 8), s3;
    s3.add(s1, s2);
    s3.display();
}
