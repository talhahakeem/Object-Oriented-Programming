#include <iostream>
using namespace std;

class car
{
private:
    string name;
    char direct;
    int position;

public:
    car(string n, char d, int p)
    {
        name = n;
        direct = d;
        position = p;
    }
    char turn()
    {
        if (direct == 'E')
        {
            return 'S';
        }
        else if (direct == 'S')
        {
            return 'W';
        }
        else if (direct == 'W')
        {
            return 'N';
        }
    }
    char turn(char d)
    {
        return 'S';
    }
    int move(int p)
    {
        position = p;
        return position;
    }
};

int main()
{
    car c1("civic", 'W', 0);
    cout << c1.turn();
    cout << endl;

    cout << c1.turn('E');
    cout << endl;

    cout << c1.move(67);
}