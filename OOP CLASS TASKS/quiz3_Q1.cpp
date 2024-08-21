#include <iostream>
using namespace std;
class Profit
{
private:
    string pdname;
    int price;
public:
    Profit(string n, int p)
    {
        pdname=n;
        price=p;
    }
    bool operator>(Profit p)
    {
        return price > 500;
    }
    Profit operator-(int val)
    {
        Profit temp = *this;
        if (temp.price > 500)
        {
            temp.price -= val;
        }
        return temp;
    }
    bool operator<(Profit p)
    {
        return price < 500;
    }
    Profit operator+(int val)
    {
        Profit temp = *this;
        if (temp.price < 500) {
            temp.price += val;
        }
        return temp;
    }
   string getName()
    {
        return pdname;
    }
    int getPrice()
    {
        return price;
    }
};
int main() {
    Profit p1("Product A", 600);
    Profit p2("Product B", 400);
    if (p1 > p1)
    {
        p1 = p1 - 200;
        cout << "Price of " << p1.getName() << " after discount: " << p1.getPrice() << endl;
    }
    if (p2 < p2)
    {
        p2 = p2 + 100;
        cout << "Price of " << p2.getName() << " after increment: " << p2.getPrice() << endl;
    }
    return 0;
}