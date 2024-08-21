#include<iostream>
using namespace std;
class University
{
    protected:
    string Program;
    string semester;
    University()
    {
        Program="BSCS";
        semester="2nd";
    }
    University(string pro,string sem)
    {
        Program=pro;
        semester=sem;
    }
    void display_uni()
    { 
        cout<<"PROGRAM:"<<Program<<endl;
        cout<<"SEMESTER:"<<semester<<endl;
    }
};
class Student:public University
{
    private:
    int roll_num;
    string name;
    string gender;
    string section;
    double gpa;
    public:
    Student()
    {
        roll_num=193;
        name="TALHA";
        gender="MALE";
        section="2F";
        gpa=3.85;
        cout<<"con 4 of 4  ";
    }
    Student(int r,string n,string s)
    {
        roll_num=r;
        name=n;
        section=s;
       
    }
    Student(string g,double G)
    {
        gender=g;
        gpa=G;
         cout<<"con 2 of 2  ";
    }
    Student(int r,string n,string s,string g,double G,string p,string sem):Student(g,G)
    {
        roll_num=r;
        name=n;
        section=s;
        gender=g;
        gpa=G;
         cout<<"con 3 of 3  ";
    }
    void display_student()
    {
        University::display_uni();
        cout<<"ROLL N0:"<<roll_num<<endl;
        cout<<"NAME:"<<name<<endl;
        cout<<"SECTION:"<<section<<endl;
        cout<<"GENDER: "<<gender<<endl;
        cout<<"GPA:"<<gpa<<endl;
    }
};
int main()
{
    Student s1;
    Student s2("MALE",3.85),s3(193,"TALHA","2F"),s4(193,"TALHA","2F","MALE",3.85,"BSCS","2ND");
    s1.display_student();
    return 0;
}