//ABSTRACT CLASS
#include <iostream>
using namespace std;
class Base
{
public:
    virtual void display() = 0; // Pure virtual function
};
class Derived : public Base
{
public:
    void display() {
        cout << "This is Abstract Class.";
    }
};
int main() {
    Derived d;
    d.display();
    return 0;
} 

//CONCRETE CLASS
#include <iostream>
using namespace std;
class Concrete {
public:
    void display() {
        cout << "This is a concrete class.";
    }
};
int main() {
    Concrete obj;
    obj.display();
    return 0;
}
