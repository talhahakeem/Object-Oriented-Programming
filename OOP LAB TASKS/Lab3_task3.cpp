#include <iostream>
using namespace std;
class Car
{
private:
    int wheels;
    int doors;

public:
    int cur_speed;
    Car()
    {
        wheels = 4;
        doors = 2;
        cur_speed = 0;
    }
    Car(int x, int y, int z)
    {
        wheels = x;
        doors = y;
        cur_speed = z;
    }
    void speed()
    {
        cur_speed += 5;
        cout << "Current Speed is: " << cur_speed << endl;
    }
    void brake()
    {
        cur_speed -= 5;
        cout << "Current Speed is: " << cur_speed << endl;
    }
};
int main()
{
    Car ferrari;
    Car hino(10, 4, 0);
    cout << "Details For Ferrari Car: \n";
    ferrari.speed();
    ferrari.brake();
    cout << "Details For Hino Car: \n";
    hino.speed();
    hino.brake();

    return 0;
}
