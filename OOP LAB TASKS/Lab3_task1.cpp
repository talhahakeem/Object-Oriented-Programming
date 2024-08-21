#include <iostream>
using namespace std;
class employee
{
private:
    int id;
    string name;

public:
    employee(int ID, string Name)
    {
        id = ID;
        name = Name;
    }
    void displayinfo()
    {
        cout << "Entered ID is: " << id << endl;
        cout << "Entered Name is" << name << endl;
    };
};
int main()
{
    employee person1(4567, "TALHA");
    employee person2(6789, "MAZHAR");
    cout << "Person 1 Details:\n";
    person1.displayinfo();
    cout << "Person 2 Details:\n";
    person2.displayinfo();
    return 0;
}