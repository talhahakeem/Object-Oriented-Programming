#include <iostream>
using namespace std;
class Time
{
    int hours;
    int minutes;
    int seconds;

public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int h, int m,int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void displayTime() const
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    void addTime(const Time &t1, const Time &t2)
    {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + (seconds / 60);
        hours = t1.hours + t2.hours + (minutes / 60);
        seconds %= 60;
        minutes %= 60;
    }
};
int main()
{
    Time t1(11, 59, 59);
    Time t2(2, 30, 30);
    Time t3;
    t3.addTime(t1, t2);
    t3.displayTime();
    return 0;
}
