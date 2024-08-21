#include <iostream>
using namespace std;
class CAR
{
    string name;
    string colour;
    int model;

public:
    void in()
    {
        cout << "Enter the Details of Car: \n";
        cout << "Enter the Name of the Car: ";
        cin >> name;
        cout << "Enter the Colour of the Car : ";
        cin >> colour;
        cout << "Enter the Car Model: ";
        cin >> model;
    }
    void out()
    {
        cout << "Entered Car details are: \n";
        cout << "Name of Car: " << name << endl;
        cout << "Colour of Car: " << colour << endl;
        cout << "Model of the Car is: " << model;
    }
};
int main()
{
    CAR c;
    c.in();
    c.out(); 
    return 0;
}