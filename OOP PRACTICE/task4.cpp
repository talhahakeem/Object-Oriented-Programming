#include <iostream>
#include <string>
using namespace std;
class Student
{
    string name;
    int age;
    string address;

public:
    Student()
    {
        name = "unknown";
        age = 0;
        address = "not available";
    }
    void setInfo(string Name, int Age)
    {
        name = Name;
        age = Age;
    }
    void setInfo(string Name, int Age, string Address)
    {
        name = Name;
        age = Age;
        address = Address;
    }
    void printInfo()
    {
        cout << "Name: " << name << ", Age: " << age << ", Address: " << address << endl;
    }
};
int main()
{
    Student s1, s2, s3, s4;
    s2.setInfo("Talha", 20, "Lahore");
    s3.setInfo("Ahmad", 18);
    s4.setInfo("Ali", 21);
    s1.printInfo();
    s2.printInfo();
    s3.printInfo();
    s4.printInfo();
    return 0;
}
