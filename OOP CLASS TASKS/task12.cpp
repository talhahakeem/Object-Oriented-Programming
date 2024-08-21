#include <iostream>
using namespace std;
class Student
{
    private:
    int id;
    string name;
    public:
    Student(int i, string n)
    {
        id=i;
        name=n;
    }
    virtual void get_data()
     {
        cout<<"Enter your Name:";
        cin>>name;
        cout << "Enter your ID: ";
        cin >> id;
    }
    virtual void show_data()
     {
        cout<<"NAME: "<<name<<endl;
        cout << "ID: " << id << endl;
    }
};
class Teacher
{
    private:
    string sub;
    string name;
    public:
    Teacher(string n, string s)
    {
        n=name;
        sub=s;
    }
    virtual void get_data()
     {
        cout<<"Enter your Name:";
        cin>>name;
        cout << "Enter the Subject: ";
        cin >> sub;
    }
    virtual void show_data()
     {
        cout<<"NAME: "<<name<<endl;
        cout << "SUBJECT: " << sub << endl;
    }
};
class University : public Student, public Teacher
{
    private:
    int year;
    string name;
    public:
    University(string n, int i, string s, int y) :Student(i, n), Teacher(n, s),name(n),year(y) {}
    void get_data() override
    {
        cout << "Enter The Year: ";
        cin >> year;
        cout<<"Enter the University Name:";
        cin>>name;
    }
    void show_data() override
    {
        cout<<"YEAR: "<<year<<endl;
        cout<<"NAME:"<<name<<endl;
    }
};
int main()
 {
    Student *ptr1;
    Teacher *ptr2;
    University u("TALHA", 193, "00P", 2024);
    ptr1=&u;
    ptr2=&u;
    ptr1->get_data();
    ptr2->get_data();
    

    ptr2->show_data();
    ptr2->show_data(); 
    return 0;
}
