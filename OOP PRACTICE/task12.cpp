#include <iostream>
using namespace std;

class emp
{
private:
    int eno;
    char enam;

public:
emp():eno(44),enam('h'){}
    // emp()
    // {
    //     eno = 44;
    //     enam = 'h';
    // }
    ~emp()
    {
        cout << "Destructor";
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
