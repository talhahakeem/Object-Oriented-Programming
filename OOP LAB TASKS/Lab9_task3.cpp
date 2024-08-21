#include <iostream>
using namespace std;
class Employee {
protected:
    string name;
public:
    Employee(string n)
    {
        name=n;
    }
    virtual double calculateSalary()
    {
        return 0;
    };
    virtual void displayInfo() {
        cout << "Name: " << name << "\n";
    }
};
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
    FullTimeEmployee(string name) : Employee(name)
    {
        monthlySalary=80000;
    } 
    double calculateSalary() override
    {
        return monthlySalary;
    }
    void displayInfo() override
    {
        Employee::displayInfo();
        cout << "Salary: " << monthlySalary << "\n";
    }
};
class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(string name, int hours) : Employee(name)
    {
        hoursWorked=hours;
        hourlyRate=5000;
    }
    double calculateSalary() override
    {
        return hourlyRate * hoursWorked;
    }
    void displayInfo() override {
        Employee::displayInfo();
        cout << "Salary: " << calculateSalary() << "\n";
    }
};
int main() {
    FullTimeEmployee fullTime("Talha");
    PartTimeEmployee partTime("Ahmad", 12);
    cout << "FULL TIME EMPLOYEE DETAILS:"<<endl;
    fullTime.displayInfo();
    cout << "PART TIME EMPLOYEE DETAILS:"<<endl;
    partTime.displayInfo();
    return 0;
}
