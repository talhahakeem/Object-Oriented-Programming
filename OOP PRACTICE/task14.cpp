#include <iostream>
using namespace std;

class Demo
{
    int x;

public:
    void set_data(int);

    int get_data() const;
};
// Function definition for setting the value of x.
void Demo::set_data(int a)
{
    x = a;
}
// Function definition for retrieving the value of x (const
// member function).
int Demo::get_data() const
{
    return x;
}
int main()
{
    Demo d;
    d.set_data(10);
    cout << d.get_data();
    return 0;
}
