#include <iostream>
using namespace std;

class Teacher
{
    int id;

public:
    int salary;
    Teacher()
    {
        salary = 0;
    }
    void Name()
    {
        cout << "Name of Teacher is Sir Awais.";
    }
    void subject()
    {
        cout << "Teacher is Teaching the OOP.";
    }
    void setSalary(int s)
    {
        salary = s;
    }
    void displaysalary()
    {
        cout << "Salary of Teacher is: " << salary << endl;
    }
};
class Student : public Teacher
{
    int age;

public:
    Student()
    {
        age = 0;
    }
    void program()
    {
        cout << "Student is Studying BSCS.";
    }
    void setAge(int a)
    {
        age = a;
    }
    void displayage()
    {
        cout << "Age of the Student is : " << age;
    }
    void name()
    {
        cout << "Student name is M.TALHA";
    }
};
int main()
{
    Student S;
    S.Name();
    cout << endl;
    S.subject();
    cout << endl;
    S.setSalary(100000);
    S.displaysalary();
    cout << endl;
    S.program();
    cout << endl;
    S.setAge(20);
    S.displayage();
    cout << endl;
    S.name();
    return 0;
}