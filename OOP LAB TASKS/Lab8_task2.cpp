#include <iostream>
using namespace std;
class Teacher
{
protected:
    string name;
    int teacherId;
public:
    void getdata()
    {
        cout << "Enter teacher's name: ";
        cin >> name;
        cout << "Enter teacher ID: ";
        cin >> teacherId;
    }
    void putdata()
    {
        cout << "Teacher's Name: " << name << endl;
        cout << "Teacher ID: " << teacherId << endl;
    }
};
class Student : public Teacher
{
private:
    int m1, m2, m3;

public:
    void getdata()
    {
        Teacher::getdata();
        cout << "Enter marks for m1: ";
        cin >> m1;
        cout << "Enter marks for m2: ";
        cin >> m2;
        cout << "Enter marks for m3: ";
        cin >> m3;
    }
    void putdata()
    {
        Teacher::putdata();
        cout << "Marks m1: " << m1 << endl;
        cout << "Marks m2: " << m2 << endl;
        cout << "Marks m3: " << m3 << endl;
    }
};
int main()
{
    Student student;
    student.getdata();
    student.putdata();
    return 0;
}
