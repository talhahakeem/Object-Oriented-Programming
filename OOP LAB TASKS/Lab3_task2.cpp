#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int age;

public:
    Student()
    {
    }
    Student(string Name, int Age)
    {
        name = Name;
        age = Age;
    }
    Student(Student &obj)
    {
        name = obj.name;
        age = obj.age;
    }
    void showall()
    {
        cout << "Name :" << name << endl;
        cout << "Age :" << age << endl;
    }
};
int main()
{
    Student obj1;
    cout << "Details for Object 1 : \n";
    obj1.showall();
    Student obj2("TALHA", 20);
    cout << "Details for Object 2 : \n";
    obj2.showall();
    Student obj3(obj2);
    cout << "Details for Object 2 : \n";
    obj3.showall();
    return 0;
}