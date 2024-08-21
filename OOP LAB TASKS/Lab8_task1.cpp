#include <iostream>
using namespace std;
class Vehicle
{
protected:
    int year;
public:
    Vehicle(int y)
    {
        year = y;
    }
    void display_year()
    {
        cout << "Vehicle Year: " << year << endl;
    }
};
class Car : public Vehicle
{
private:
    string make;
    string model;

public:
    Car(int y, string m, string mo) : Vehicle(y), make(m), model(mo) {}
    void display()
    {
        display_year();
        cout << "Car Make: " << make << "\nCar Model: " << model << endl;
    }
};
int main()
{
    Car myCar(2024, "Honda", "Civic");
    myCar.display();
    return 0;
}
