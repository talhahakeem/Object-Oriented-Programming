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
    time add(time t1, time t2)
    {
        time t;
        t.h = h + t1.h + t2.h;
        t.m = m + t1.m + t2.m;
        t.s = s + t1.s + t2.s;
        return t;
    }
};
int main()
{
    time s1(1, 6, 8);
    time s2(5, 7, 8);
    time s3(8, 7, 8);
    time s4 = s3.add(s3, s2);
    s4.display();
}
