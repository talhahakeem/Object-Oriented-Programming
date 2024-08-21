#include <iostream>
using namespace std;
class Teacher
{
public:
    int salary;
    void Name()
    {
        cout << "Name of Teacher is Sir Awais.";
    }
    void subject()
    {
        cout << "Teacher is Teaching the OOP.";
    }
    void Salaryset()
    {
        salary = 100000;
    }
    void displaysalary()
    {
        cout << "Salary of Teacher is: " << salary << endl;
    }
};
class Student : public Teacher
{
    int Age;

public:
    void program()
    {
        cout << "Student is Studying BSCS.";
    }
    void ageset()
    {
        Age = 20;
    }
    void displayAge()
    {
        cout << "Age of the Student is : " << Age;
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
    S.subject();
    S.Salaryset();
    S.displaysalary();
    S.program();
    S.ageset();
    S.displayAge();
    S.name();
    return 0;
}