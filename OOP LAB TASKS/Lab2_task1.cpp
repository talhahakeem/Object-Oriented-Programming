#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    int reg_num;
    float percentage;

public:
    void inputdata()
    {
        cout << "Enter the Name: ";
        cin >> name;
        cout << "Enter the Registeration number: ";
        cin >> reg_num;
        cout << "Enter the percentage: ";
        cin >> percentage;
    }
    void displaydata()
    {
        cout << "DISPLAY DATA:\n";
         cout << "Entered Name is: " << name << endl;
        cout << "Entered Registeration number is" << reg_num << endl;
        cout << "Entered Percentage is: " << percentage << endl;
    }
};
int main()
{
    Student talha;
    talha.inputdata();
    talha.displaydata();
    return 0;
}