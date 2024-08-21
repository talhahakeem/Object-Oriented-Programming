#include <iostream>
using namespace std;
class Demo
{
    int value;

public:
    Demo()
    {
        value = 0;
    }
    void showMessage()
    {
        cout << "non constant showMessage() Function" << endl;
    }
    // const member function
    void display() const
    {
        cout << "Constant display() Function"
             << endl;
    }
};
int main()
{
    const Demo d1;
    // d1.showMessage();Error occurred if uncomment.
    d1.display();
    return (0);
}
