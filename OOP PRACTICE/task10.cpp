w#include <iostream>
using namespace std;
#include <string>
class EidMubarak
{
public:
    void sendWishes(const string &name)
    {
        cout << "Eid Mubarak, " << name << "! May this special day bring peace, happiness and prosperity to you.\n";
    }
};

int main()
{
    EidMubarak eid;
    string name = "Dear!";
    eid.sendWishes(name);
    return 0;
}
