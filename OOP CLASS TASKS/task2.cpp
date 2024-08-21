#include <iostream>
using namespace std;

class student
{
private:
    float marks;
    string name;
    float percentage;

public:
    void setData(string n, int m)
    {
        marks = m;
        name = n;
    }
    void Percentage(float t)
    {
        percentage = t / 500 * 100;
    }

    void display()
    {
        cout << "Name of student is: " << name << endl;
        cout << "Marks of Student is: " << marks << endl;
        cout << "Percentage of Student is: " << percentage << endl;
    }
};

int main()
{
    int size = 5;
    student *ptr = new student[size];
    student *temp = ptr;
    float m;
    string n;
    float p;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name of student " << i + 1 << endl;
        cin >> n;
        cout << "Enter " << i + 1 << " marks: " << endl;
        cin >> m;
        ptr->setData(n, m);
        ptr->Percentage(m);

        ptr++;
    }

    for (int i = 0; i < size; i++)
    {
        temp->display();
        temp->Percentage(m);
        temp++;
    }

    return 0;
}