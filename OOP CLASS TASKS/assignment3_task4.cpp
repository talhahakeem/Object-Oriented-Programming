#include<iostream>
using namespace std;
class myClass {
public:
    int value;
    myClass(int val = 0) : value(val) {}
    myClass operator+(myClass &a) {
        myClass temp;
        temp.value = this->value + a.value;
        return temp;
    }
    myClass operator*(myClass &a) {
        myClass temp;
        temp.value = this->value * a.value;
        return temp;
    }
    void display() 
    {
    cout << "Value: " << value << endl;
    }
};
int main() {
    myClass object1(10), object2(20), object3, object4;
    object3 = object1 + object2;
    object4 = object3 * object2;
    object3.display();
    object4.display();
    return 0;
}