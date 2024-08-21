#include <iostream>
using namespace std;

class Demo
{
    int x;

public:
    void set_data(int a)
    {
        x = a;
    }
    // constant member function
    int get_data() const
    {
        // Error while attempting to modify the data
        // member
        ++x;
        return x;
    }
};
int main()
{
    Demo d;
    d.set_data(10);
    cout << endl
         << d.get_data();

    return 0;
}
