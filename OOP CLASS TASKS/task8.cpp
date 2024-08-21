#include <iostream>
using namespace std;
class student
{
private:
    char name[20];
    int rno;

public:
    void getstudent()
    {
        cout << "Enter the Name of Student: ";
        cin >> name;
        cout << "Enter the Roll number of Student: ";
        cin >> rno;
    }
    void displaystudent()
    {
        cout << "Entered Student Name is : " << name << endl;
        cout << "Entered Roll number of Student is : " << rno << endl;
    }
};
class test : public student
{
protected:
    int math, eng, sci;

public:
    void gettest()
    {
        cout << "Enter the Marks Of Subjects :";
        cin >> math >> eng >> sci;
    }
    void displaytest()
    {
        cout << "Entered Marks Of Subjects Are : " << math << " " << eng << " " << sci << " " << endl;
    }
};
class adress
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
        cout << "Entered City Name is : " << city << endl;
    }
};
class result : public test, public adress
{
private:
    int total, avg;

public:
    void getresult()
    {
        getstudent();
        gettest();
        getadress();
        cout << "Enter your Final marks: ";
        cin >> total;
    }
    void displayresult()
    {
        displaystudent();
        displaytest();
        displayadress();
        cout << "Your Total Marks Are : " << total << endl;
    }
};
int main()
{
    result r;
    r.getresult();
    r.displayresult();
    return 0;
}