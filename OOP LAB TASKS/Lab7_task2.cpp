#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
    string name, department;
    double salary;
    Employee(string n, string d, double s)
    {
        name = n;
        department = d;
        salary = s;
    }
};
class Company
{
public:
    Employee **employees;
    int size;
    Company(int n)
    {
        size = n;
        employees = new Employee *[n];
        for (int i = 0; i < n; i++)
        {
            employees[i] = nullptr;
        }
    }
    ~Company()
    {
        for (int i = 0; i < size; i++)
        {
            delete employees[i];
        }
        delete[] employees;
    }
    void addEmployee(int index, string name, string department, double salary)
    {
        if (index >= 0 && index < size)
        {
            employees[index] = new Employee(name, department, salary);
        }
    }
    void displayEmployees()
    {
        for (int i = 0; i < size; i++)
        {
            if (employees[i] != nullptr)
            {
                cout << "Employee " << i + 1 << ": " << employees[i]->name << ", " << employees[i]->department << ", " << employees[i]->salary << endl;
            }
        }
    }
    void searchEmployee(string searchValue)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (employees[i] != nullptr)
            {
                if (employees[i]->name == searchValue || employees[i]->department == searchValue || to_string(employees[i]->salary) == searchValue)
                {
                    cout << "Employee found: " << employees[i]->name << ", " << employees[i]->department << ", " << employees[i]->salary << endl;
                    count++;
                }
            }
        }
        if (count != 0)
        {
            cout << "Employee not found." << endl;
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    Company company(n);
    for (int i = 0; i < n; i++)
    {
        string name, department;
        double salary;
        cout << "Enter details for employee " << i + 1 << " (name, department, salary): ";
        cin >> name >> department >> salary;
        company.addEmployee(i, name, department, salary);
    }
    company.displayEmployees();
    string searchValue;
    cout << "Enter name, department, or salary of the employee to search: ";
    cin >> searchValue;
    company.searchEmployee(searchValue);
    return 0;
}