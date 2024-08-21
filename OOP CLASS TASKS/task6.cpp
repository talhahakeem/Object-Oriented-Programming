#include <iostream>
using namespace std;
class base
{
private:
    char name[20];
public:
    void getstudent()
    {
        cout << "Enter the Student Name: ";
        cin >> name;
    }
    void displaystudent()
    {
        cout << "Entered Student Name is: " << name << endl;
    }
};
class derived : public base
{
private:
    char city[20];

public:
    void getadress()
    {
        cout << "Enter the City Name: ";
        cin >> city;
    }
    void displayadress()
    {
        cout << "Entered City Name is: " << city << endl;
    }
};
int main()

{
    derived d;
    d.getstudent();
    d.displaystudent();

    return 0;
}