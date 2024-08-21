#include <iostream>
using namespace std;

class Student
{
    private:
    int id;
    string name;
    public:
    Student(int i, string n) :id(i),name(n){}
    virtual void get_data()
    {
        cout << "Enter your Name: ";
        cin >> name;
        cout<<"Enter Your ID: ";
        cin>>id;
    }
    virtual void show_data()
    {
        cout<<"NAME: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
    }
};
class Teacher
{
    private:
    string name;
    int age;
    public:
    Teacher(string n,int a) : name(n), age(a) {}
    virtual void get_data()
    {
        cout << "Enter The Name : ";
        cin >> name;
        cout<<"Enter the AGE: ";
        cin>>age;
    }
    virtual void show_data()
    {
        cout<<"NAME: "<<name<<endl;
        cout<<"AGE: "<<age<<endl;
    }
};
class Person:public Student,public Teacher
 {
    private:
    int age;
    string name;
    public:
    Person(string n,int a,int i):Student(i,n),Teacher(n,a),name(n){}
    void get_data() override
    {
        cout << "Enter the Name: ";
        cin >> name;
        cout<<"Enter the AGE: ";
        cin>>age;
    }
    void show_data() override
    {
        cout << "Name: " << name << endl;
        cout<<"AGE: "<<age<<endl;
    }
};
int main()
{
    Student *ptr1;
    Teacher *ptr2;
    Person p("TALHA",20,193);
    ptr1=&p;
    ptr2=&p;
    ptr1->get_data();
    ptr2->get_data();
    
    ptr2->show_data();
    ptr2->show_data();
    return 0;
}
