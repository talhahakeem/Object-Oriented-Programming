#include<iostream>
using namespace std;
class Vehicle
{
    protected:
    int price;
    int mileage;
    public:
    void get_vehicledata()
    {
        cout<<"Enter the Price: ";
        cin>>price;
        cout<<"Enter the Mileage: ";
        cin>>mileage;
    }
    void display_vehicle()
    {
        cout<<"PRICE:"<<price<<endl;
        cout<<"MILEAGE:"<<mileage<<endl;
    }
};
class Car:public Vehicle
{
    protected:
    int own_cost;
    int warr;
    int capacity;
    string fuel_type;
    public:
    void get_Cardata()
    {
        Vehicle::get_vehicledata();
        cout<<"Enter the Owner cost: ";
        cin>>own_cost;
        cout<<"Enter the Warranty (by years):";
        cin>>warr;
        cout<<"Enter the Seating Capacity: ";
        cin>>capacity;
        cout<<"Enter the Fuel Type: ";
        cin>>fuel_type;
    }
    void display_Car()
    {
        Vehicle::display_vehicle();
        cout<<"OWNER COST: "<<own_cost<<endl;
        cout<<"WARRANTY(BY YEARS): "<<warr<<endl;
        cout<<"SEATING CAPACITY: "<<capacity<<endl;
        cout<<"FUEL TYPE: "<<fuel_type<<endl;

    }
};
class Bike:public Vehicle
{
    protected:
    int cylinder_num;
    int gear_num;
    string cool_type;
    string wheel_type;
    int size;
    public:
    void get_Bikedata()
    {
        Vehicle::get_vehicledata();
        cout<<"Enter the Number of cylinders: "<<cylinder_num;
        cin>>cylinder_num;
        cout<<"Enter the Number of gears: ";
        cin>>gear_num;
        cout<<"Enter the Cooling Type: ";
        cin>>cool_type;
        cout<<"Enter the Wheel Type: ";
        cin>>wheel_type;
        cout<<"Enter the Tank Size(in inches): ";
        cin>>size;
    }
    void display_Bike()
    {
        Vehicle::display_vehicle();
        cout<<"NUMBER OF CYLINDERS: "<<cylinder_num<<endl;
        cout<<"NUMBER OF GEARS: "<<gear_num<<endl;
        cout<<"COOLING TYPE: "<<cool_type<<endl;
        cout<<"WHEEL TYPE: "<<wheel_type<<endl;
        cout<<"TANK SIZE: "<<size<<endl;
    }
};
class Audi:public Car
{
    private:
    string model;
    public:
    void get_audi()
    {
    Car::get_Cardata();
    cout<<"Enter the Model Type:";
    cin>>model;
    }
    void display_audi()
    {
      Car::display_Car();
      cout<<"MODEL TYPE: "<<model<<endl;
    }
};
class Ford:public Car
{
    private:
    string model;
    public:
    void get_Ford()
    {
    Car::get_Cardata();
    cout<<"Enter the Model Type:";
    cin>>model;
    }
    void display_Ford()
    {
      Car::display_Car();
      cout<<"MODEL TYPE: "<<model<<endl;
    }
};
class Bajaj:public Bike
{
    private:
    string make_type;
    public:
    void get_Bajaj()
    
    {
        Bike::get_Bikedata();
        cout<<"Enter the Make Type: "; 
        cin>>make_type;
    }
    void display_Bajaj()
    {
        Bike::display_Bike();
        cout<<"MALE_TYPE:"<<make_type<<endl;
    }
};
class TVS:public Bike
{
    private:
    string make_type;
    public:
    void get_TVS()
    {
        Bike::get_Bikedata();
        cout<<"Enter the Make Type: ";
        cin>>make_type;
    }
    void display_TVS()
    {
        Bike::display_Bike();
        cout<<"MAKE_TYPE:"<<make_type<<endl;
    }
};
int main()
{
    Audi A;
    cout<<"ENTER DETAILS FOR AUDI:\n";
    A.get_audi();
    cout<<"ENTERED DETAILS FOR AUDI:\n";
    A.display_audi();
    Ford F;
    cout<<"ENTER DETAILS FOR FORD:\n";
    F.get_Ford();
    cout<<"ENTERED DETAILS FOR FORD:\n";
    F.display_Ford();
    Bajaj B;
    cout<<"ENTER DETAILS FOR BAJAJ:\n";
    B.get_Bajaj();
    cout<<"ENTERED DETAILS FOR BAJAJ:\n";
    B.display_Bajaj();
    TVS T;
    cout<<"ENTER DETAILS FOR TVS:\n";
    T.get_TVS();
    cout<<"ENTERED DETAILS FOR TVS:\n";
    T.display_TVS();
    return 0;
}