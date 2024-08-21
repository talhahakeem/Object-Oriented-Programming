#include <iostream>
using namespace std;

class emp
{
private:
    int eno;
    string enam;

public:
    emp()
    {
        eno = 4567;
        enam = "Talha Malik";
    }
    ~emp()
    {
        cout << "This is Destructor and can be called at the end of the program automatically";
    }
    void show()
    {
        cout << "Employee No:" << eno << endl;
        cout << "Employee Name:" << enam << endl;
    }
};
int main()
{
    emp e;
    e.show();
}
