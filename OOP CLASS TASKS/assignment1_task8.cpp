#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    string Class;
    int RollNum;
    double Marks;

public:
    Student(string Name, string class_, int rollNum, double marks)
    {
        name = Name;
        Class = class_;
        RollNum = rollNum;
        Marks = marks;
    }
    string calculateGrade()
    {
        if (Marks >= 90)
        {
            return "A+";
        }
        else if (Marks >= 80)
        {
            return "A";
        }
        else if (Marks >= 70)
        {
            return "B";
        }
        else if (Marks >= 60)
        {
            return "C";
        }
        else
        {
            return "D";
        }
    }
    void displayInformation()
    {
        cout << "Name: " << name << endl;
        cout << "Class: " << Class << endl;
        cout << "Roll Number: " << RollNum << endl;
        cout << "Marks: " << Marks << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }
};
int main()
{
    Student student("Talha", "2F", 193, 86);
    student.displayInformation();
    return 0;
}
