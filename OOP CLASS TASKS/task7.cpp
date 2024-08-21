#include <iostream>
using namespace std;
class student
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
class test : public student
{
protected:
    int math, eng, sci;
public:
    void gettest();
    void displaytest();
};
class result : public test
{
private:
    int total, avg;

public:
    void getresult();
    void displayresult();
};
int main()
{
    return 0;
}