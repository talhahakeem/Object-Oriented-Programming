#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    string name;
    int employeeId;
    double salary;
public:
    void getEmployee_data()
    {
        cout<<"Enter the Employee name: ";
        cin>>name;
        cout<<"Enter the Employee ID: ";
        cin>>employeeId;
        cout<<"Enter the Employee Salary: ";
        cin>>salary;
    }
    void display_employeedata() const {
        cout << "Name: " << name << ", Employee ID: " << employeeId << ", Salary: $" << salary << endl;
    }
};
class Developer : public Employee {
private:
   string Language;
public:
    void getDeveloper_data()
    {
        getEmployee_data();
        cout<<"Enter the Programming Language: ";
        cin>>Language;
    }
    void display_Developerdata() const
    {
        cout << "Developer: \n";
            display_employeedata();
            cout << "Programming Language: " <<Language << endl;
    }
};
class Manager : public Employee {
protected:
    int teamSize;
public:
    void get_Managerdata()
    {
    getEmployee_data();
    cout<<"Enter the NO. of Team Members: ";
    cin>>teamSize;
    }
    void display_Managerdata() const {
        cout << "Manager: \n";
        display_employeedata();
        cout << "Team Size: " << teamSize << " members" << endl;
    }
};
class HRManager : public Manager {
private:
    string department;
public:
    void get_HRManagerdata()
    {
    get_Managerdata();
    cout<<"Enter The Department Name: ";
    cin>>department;
    }
    void display_HRManagerdata() const {
        cout << "HR Manager: \n";
        display_Managerdata();
        cout << "Department: " << department << endl;
    }
};
class QAEngineer : public Employee {
private:
    string testingtool;

public:
    void get_QAEngineerdata()
    {
     getEmployee_data();
     cout<<"Enter the testingtool Name:  ";
     cin>>testingtool;
    }
    void display_QAEngineerdata() const {
        cout << "QA Engineer :\n";
        display_employeedata();
       cout << "Testing Tool: " << testingtool <<endl;
    }
};
class SalesExecutive : public Employee {
private:
    int salestarget;
public:
    void get_SalesExecutivedata()
    {
     getEmployee_data();
     cout<<"Enter the Sales Taget: ";
     cin>>salestarget;
    }
    void display_Salesdata() const {
        cout << "Sales Executive: \n";
        display_employeedata();
        cout << "Sales Target: $" << salestarget << endl;
    }
};
class TechnicalLead : public Manager {
private:
    string tech;
public:
    void get_TechnicalLeaddata()
    {
     get_Managerdata();
     cout<<"Enter the Technology Name: ";
     cin>>tech;
    }
    void display_TechnicalLeaddata() const {
        cout << "Technical Lead :\n";
        display_Managerdata();
        cout << "Technology: " << tech << endl;
    }
};
class ProductManager : public Manager {
private:
    string product;
public:
    void get_ProductManagerdata()
    {
    get_Managerdata();
    cout<<"Enter the Product Name: ";
    cin>>product;
    }
    void display_ProductManagerdata() const {
        cout << "Product Manager: \n";
         display_Managerdata();
        cout << "Product: " << product <<endl;
    }
};
int main() {
    Developer dev;
    Manager mgr;
    HRManager hrmgr;
    QAEngineer qaEng;
    SalesExecutive salesExec;
    TechnicalLead techLead;
     ProductManager prodMgr;
     cout<<"========================================================\n";
     cout<<"SOFTWARE HOUSE EMPLOYEES DETAILS: \n";
     cout<<"========================================================\n";
    cout<<"DEVELOPER DETAILS: \n";
    dev.getDeveloper_data();
    cout<<"MANAGER DETAILS: \n";
    mgr.get_Managerdata();
    cout<<"HR MANAGER DETAILS: \n";
    hrmgr.get_HRManagerdata();
    cout<<"QA ENGINEER DETAILS: \n";
    qaEng.get_QAEngineerdata();
    cout<<"SALES EXECUTIVE DETAILS: \n";
    salesExec.get_SalesExecutivedata();
    cout<<"TECHNICAL LEAD DETAILS: \n";
    techLead.get_TechnicalLeaddata();
    cout<<"PRODUCT MANAGER DETAILS: \n";
    prodMgr.get_ProductManagerdata();
    cout<<"=========================================================\n";
    cout<<"EMPLOYEES INFOMATION: \n";
    cout<<"=========================================================\n";
    dev.display_Developerdata();
    mgr.display_Managerdata();
    hrmgr.display_HRManagerdata();
    qaEng.display_QAEngineerdata();
    salesExec.display_Salesdata();
    techLead.display_TechnicalLeaddata();
    prodMgr.display_ProductManagerdata();
    return 0;
}