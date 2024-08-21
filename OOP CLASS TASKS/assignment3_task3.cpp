#include<iostream>
using namespace std;
class myClass {
    int value;
public:
    myClass() : value(0) {}
    myClass(int val) : value(val) {} 
    myClass operator+ (int num) {
        myClass temp;
        temp.value = this->value + num;
        return temp;
    }
    void display() {
        cout << "Value: " << value << endl;
    }
};
int main() {
    int a = 5;
    myClass object1(10), object2;
    object2 = object1 + a;
    object2.display();
    return 0;
}